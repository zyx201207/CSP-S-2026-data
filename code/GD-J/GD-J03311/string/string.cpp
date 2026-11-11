#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
char c[N];
unsigned long long times,n,tag,all;
int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    char p;
    for(int i=0;i<n;i++){
        cin>>times>>p;
        all+=times;
        int more=tag;
        for(int i=more;i<=more+times-1;i++){
            c[i]=p;
            tag+=times-1;
        }
    }
    int point1=0,point2=all-1;
    all/=2;
    while(point2>all){
        if(c[point1]!=c[point2]) ans++;
        point1++;point2--;
    }
	cout<<ans;
    return 0;
}
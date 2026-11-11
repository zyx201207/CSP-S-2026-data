#include<bits/stdc++.h>
using namespace std;
unsigned long long n;
string ans;
unsigned long long tnt,sum;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        int m;
        string a;
        cin>>m>>a;
        tnt+=m;
        for(int j=1;j<=m;j++){
        	ans+=a;
		}
    }
    long long l=0,r=tnt-1;
    while(l!=r&&l<r){
        if(ans[l]!=ans[r]){
            sum++;
        }
        l++;
        r--;
    }
    cout<<sum;
    return 0;//Trick||Treat!
}

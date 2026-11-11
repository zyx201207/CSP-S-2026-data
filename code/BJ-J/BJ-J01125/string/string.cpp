#include<bits/stdc++.h>
using namespace std;
int n,x=1,y,a[200007];
long long sum,cnt;
char c[200007];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    y=n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    for(int i=1;i<=sum/2;i++){
        if(c[x]!=c[y]){
            cnt++;
        }
        a[x]--,a[y]--;
        if(!a[x]){
            x++;
        }
        if(!a[y]){
            y--;
        }
    }
    cout<<cnt;
    return 0;
}

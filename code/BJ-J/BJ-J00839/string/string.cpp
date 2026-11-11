#include <bits/stdc++.h>
using namespace std;

struct a{
    int num;
    char s;
};
a m[10004];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long cnt=0,ans=0,n,x=100,y=100;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m[i].num>>m[i].s;
        cnt+=m[i].num;
    }
    cnt/=2;
    int i=1,j=n;
    x=m[i].num;
    y=m[n-i+1].num;
    while(cnt>0){
        if(m[i].s!=m[j].s){
            ans++;
        }
        x--;
        y--;
        cnt--;
        if(x==0){
            i++;
            x=m[i].num;

        }
        if(y==0){
            j--;
            y=m[j-1].num;

        }
    }
    cout<<ans;
    return 0;
}


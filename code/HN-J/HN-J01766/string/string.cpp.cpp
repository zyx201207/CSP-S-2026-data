#include <bits/stdc++.h>
using namespace std;
long long cnt,n,a,b,ans;
string c,d,e;
bool flag;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>d;
        cnt+=a;
        if(i==1){
            e=d;
        }
        if(e==d){
            flag=1;
        }else{
            flag=0;
        }

        for(int i=1;i<=a;i++){
            c=c+d;
        }
    }
    if(flag==1){
        cout<<ans;
    }else{
        int i=0;
        while(cnt>0){
            if(c[0+i]!=c[cnt]){
                ans++;
            }
                i++;
                cnt=cnt-i;
            }
        cout<<ans;
    }
    return 0;
}

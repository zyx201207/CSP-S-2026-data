#include<bits/stdc++.h>
using namespace std;
#define int long long
int ans[5];
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        ans[1]=ans[2]=1;
        for(int i=0;i<=1;i++)if(s1[i]!=s2[i])ans[2]=0;
        if(ans[2]){
            if(s1[2]<='C'&&s2[2]<='C'||s1[2]>'C'&&s2[2]>'C'){
                ans[3]=1;
                if(abs((int)(s1[2]-s2[2]))==1)ans[4]=1;
            }
        }
    }
    for(int i=1;i<=4;i++)cout<<ans[i];
    return 0;
}

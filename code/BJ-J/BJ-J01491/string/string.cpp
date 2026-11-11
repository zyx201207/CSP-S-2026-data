#include <bits/stdc++.h>
using namespace std;
long long n,len[200005],ans,len1[200005],leave,leave2;
char x[200005],x1[200005];
long long tot1,tot2,lt1,lt2,tot;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i]>>x[i];
        tot+=len[i];
        len1[n-i+1]=len[i];
        x1[n-i+1]=x[i];
    }
    int ft=1,sd=1;
    tot1=len[ft];
    tot2=len1[sd];
    if(x[ft]!=x1[sd]){
        ans+=min(len[ft],len1[sd]);
    }
    while(ft<=n&&sd<=n){
        leave=tot1-tot2;
        if(leave<=0){
                ft++;
            if(x[ft]!=x1[sd]){
                ans+=abs(min(abs(leave),len[ft]));
            }
            tot1+=len[ft];

        }
        else{
                sd++;
            if(x[ft]!=x1[sd]){
                ans+=abs(min(leave,len1[sd]));
            }
            tot2+=len1[sd];

        }
    }
    if(tot%2==0) cout<<ans/2;
    else cout<<ans/2;
    return 0;
}//90minutes on it!!!!!!

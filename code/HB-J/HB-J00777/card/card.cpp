#include<bits/stdc++.h>
using namespace std;
bool v[500005];
bool t[500005];
int ma[500005];int p[500005],cnt[500003],s[500003];
int sum[500005];
   int summ[500005];
int main(){
//freopen("card.in","r",stdin);
//freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;

for(int i=1;i<=n;i++){
    cin>>p[i];
    s[i]=p[i];
    sum[p[i]]++;
    summ[p[i]]++;
}
    for(int i=1;i<=n;i++){

        for(int j=i;j<=n;j++){
                if(v[s[j]]==0){
                        v[s[j]]=1;
                        ma[s[j]]=j;
                }
                else {
                    for(int k=ma[s[j]];k<j;k++){
                        sum[s[k]]-=1;
                    }
                     ma[s[j]]=j;
                }
        }
        for(int i=1;i<=n;i++){
            if(sum[s[i]]==1){
                    cnt[s[i]]++;
                    sum[s[i]]=0;
            }
        }

       for(int i=1;i<=n;i++){
        s[i]=p[i];
        sum[i]=summ[i];
       }
    }
 for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
       }
return 0;
}


#include<bits/stdc++.h>
using namespace std;
int t[300005],sum[300005],n,m,cnt=0,k,pos2,sum1[300005];;
string s,a;
int main(){
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        a=a+s[i];
    }
    int b=n;
    while(b--){
        int pos=cnt;
        for(int i=cnt;i<=n-1;i++){
            if(t[a[i]]==1){
                pos=i;
                if(a[i]!=k&&k!=0&&pos2<=sum[a[i]]&&pos2!=0&&sum[a[i]]!=0){
                    sum[k]++;
                }
                k=a[i];
                pos2=i;
                sum1[a[i]]=i;
                t[a[i]]=0;
            }else{
                t[a[i]]++;
                sum1[a[i]]=i;
            }
        }
        for(int i=pos;i<=n-1;i++){
            sum[a[i]-'0']++;
        }
        cnt++;
        memset(t,0,sizeof(t));
        memset(sum1,0,sizeof(sum));

    }

    for(int i=1;i<=m;i++){
        if(i==a[n-1]-'0'){
            cout<<n<<" ";
        }else{
            cout<<sum[i]<<" ";
        }
    }
  fclose(stdin);
  fclose(stdout);
    return 0;
}

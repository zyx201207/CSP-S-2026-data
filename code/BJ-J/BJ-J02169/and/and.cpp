//25pts
#include<bits/stdc++.h>
using namespace std;
int a[1000010],num[1000010],acopy[1000010];
string s[1000010],scopy[1000010];
int main(){
    bool flag=1;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        acopy[i]=a[i];
        float bn=a[i]*1.0;
        num[i]=log2(bn);
        if(a[i]!=pow(2,num[i]+1)-1){
            flag=0;
        }
    }
    if(flag==1){
        sort(acopy+1,acopy+n+1);
        cout<<acopy[n];
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=num[i]+1;j++){
            s[i]+='0';
        }
        while(a[i]!=0){
            s[i]="0";
            float an=a[i]*1.0;
            int q=log2(an);

            long long ans=1;
            for(int i=1;i<=q;i++){
                ans*=2;
            }
            a[i]-=ans;
            s[i][q+1]='1';
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            long long cnt=0;
            for(int k=max(num[i]+1,num[j]+1);k>=0;k--){
                if(s[i][k]=='1'&&s[j][k]=='1'){
                    cnt+=pow(2,k-1);
                }
            }
            ans=max(ans,cnt);
        }
    }
    cout<<ans;
}

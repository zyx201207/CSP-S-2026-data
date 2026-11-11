#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],mi[500005];
int main(){
        //freopen("crystal.in","r",stdin);
        //freopen("crystal.out","w",stdout);
        int n;
        long long m;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
                cin>>a[i];
        }
        sort(a+1,a+1+n);
        for(int i=2;i<=n;i++){
                s[i]=s[i-1]+a[i]-a[1];
        }
        long long zs=s[n];
        int co=1;
        for(int i=2;i<=n;i++){
                long long no=a[i]-a[1];
                long long sum=s[n]-no*(n-i)-s[i-1];
                if(sum<=zs){
                        zs=sum;
                        co=i;
                }
        }
        for(int i=1;i<=co;i++){
                mi[i]=a[co]-a[i];
        }
        sort(mi+1,mi+1+n);
        int ans=0;
        while(m-mi[ans+1]>0&&ans<co){
        	ans++;
               m-=mi[ans];            
        }
        cout<<ans;
        return 0;
}

#include<iostream>
#include<stdio.h>
using namespace std;
int n,m;
long long mx=0;
long long a[200005],f[35],ans=0;
long long p[200005];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    f[0]=1;
        for(int i=1;i<=30;i++)
        f[i]=f[i-1]*2;
    cin>>n>>m;
        for(int i=0;i<=n+1;i++)
        p[i]=0;
        for(int i=1;i<=n;i++){
        cin>>a[i];mx=max(mx,a[i]);}
    bool pd=true;
        for(int i=30;i>=0;i--){
            if(f[i]>mx) continue;
        int num=0;
            for(int j=1;j<=n;j++)
                if(a[j]>=f[i]){
                    if(pd) p[j]++,num++;
                    else if(p[j]>0) p[j]++,num++;
                }

            if(num>=m) ans+=f[i];
            if(num>=m&&pd){pd=false;
            for(int j=1;j<=n;j++){
                if(a[j]>=f[i]){
                a[j]-=f[i];
                }
            }
            continue;}
            for(int j=1;j<=n;j++){
                if(a[j]>=f[i]){
                a[j]-=f[i];
                }
                if(num>=m&&p[j]>0) p[j]--;
            }
        }
        //for(int i=1;i<=n;i++)
            //if(p[i]>0) cout<<a[i]<<' ';
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
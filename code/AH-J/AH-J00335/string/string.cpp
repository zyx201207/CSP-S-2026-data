#include<bits/stdc++.h>
using namespace std;
long long n,n1,n2,a[200005],p[200005],a1[200005],a2[200005];
char c[200005],c1[200005],c2[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i],p[i]=p[i-1]+a[i];
    long long k=(p[n]+1)>>1;
    for(int i=1;i<=n;i++){
        if(p[i]>=k){
            long long l=p[i]-k,s,n1=i-1,n2=n-i;
            int f=0;
            if(p[n]&1){
                s=a[i]-l-1;
                for(int j=1;j<i;j++)a1[j]=a[j],c1[j]=c[j];
                if(s>0)a1[i]=s,c1[i]=c[i],n1++;
                s=a[i]-s-1;
                if(s>0)a2[1]=s,c2[1]=c[i],n2++,f=1;
                for(int j=i+1;j<=n;j++)a2[j-i+f]=a[j],c2[j-i+f]=c[j];
            }else{
                s=a[i]-l;
                for(int j=1;j<i;j++)a1[j]=a[j],c1[j]=c[j];
                if(s>0)a1[i]=s,c1[i]=c[i],n1++;
                if(s<a[i])a2[1]=a[i]-s+1,c2[1]=c[i],n2++,f=1;
                for(int j=i+1;j<=n;j++)a2[j-i+f]=a[j],c2[j-i+f]=c[j];
            }
            long long p1=1,p2=n2,ans=0;
            while(p1<=n1&&p2>=1){
                if(a1[p1]<a2[p2]){
                    if(c1[p1]!=c2[p2])ans+=a1[p1];
                    a2[p2]-=a1[p1];
                    p1++;
                }else if(a1[p1]>a2[p2]){
                    if(c1[p1]!=c2[p2])ans+=a2[p2];
                    a1[p1]-=a2[p2];
                    p2--;
                }else{
                    if(c1[p1]!=c2[p2])ans+=a1[p1];
                    p1++;
                    p2--;
                }
            }
            cout<<ans;
            break;
        }
    }
    return 0;
}

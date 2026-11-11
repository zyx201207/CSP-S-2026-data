#include<bits/stdc++.h>
using namespace std;
const int mx=5000100;
int n,b[1000010],c[1000010];
long long a[mx],m;
int i,j,cnt=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=0) b[a[i]]++;
        else c[abs(a[i])]++;
    }
    //cout<<m<<endl;
    if(n<=5000){
        for(i=1;i<=n;i++) a[i]=0;
        for(int i=-100010;i<0;i++)
            while(c[abs(i)]--) a[++cnt]=i;
        for(int i=0;i<100010;i++)
            while(b[i]--) a[++cnt]=i;
     //   for(i=1;i<=n;i++) cout<<a[i]<<" ";
        int sum=a[1],ks=0;
        int ml=-1,l=1,kk=0;
        for(i=2;i<=n;i++){
            if(a[i]*(i-1-kk)-sum<=m) {
                l++;
                ml=max(ml,l);
                sum+=a[i];
            }
            else {
                l=0;
                sum=0;
                kk=i;
            }
        }
    cout<<ml;
    }
    else{
        int x=a[2]-a[1];
        int y=-1+sqrt(4*m+1);
        y=y/2;
        cout<<y;
    }
    return 0;
}
//15 78
//-43 -40 -35 -32 -30 -28 -15 -7 0 1 2 4 11 13 17

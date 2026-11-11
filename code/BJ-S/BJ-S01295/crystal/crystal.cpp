#include<bits/stdc++.h>
#define rd read();
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans1,ans2;
ll a[N],m,sum;
inline int read(){
    char c=getchar();
    int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9')x=x*10+c-48,c=getchar();
    return x*f;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=rd;m=rd;
    for(int i=1;i<=n;i++){
        a[i]=rd;
        sum+=a[i];
    }
    sort(a+1,a+1+n);
    int m1=m,l=0,i=upper_bound(a+1,a+n+1,ceil(1.0*sum/n))-a-1,j=i+1;
    while(m){
        ll u=a[j-1]-a[i],v=l*(a[j]-a[j-1]);
        if((m<v&&m<u)||l==n)break;
        if(u<=v&&m>=u){
            if(i>=1)ans1++,l++,m-=u,i--;
            else if(m>=v)ans1++,l++,m-=v,j++;
            else break;
        }
        else if(u>v&&m>=v){
            if(j<=n)ans1++,l++,m-=v,j++;
            else if(m>=u)ans1++,l++,m-=u,i--;
            else break;
        }
    }
    m=m1;
    l=0,i=lower_bound(a+1,a+n+1,sum/n)-a,j=i+1;
    while(m){
        ll u=a[j-1]-a[i],v=l*(a[j]-a[j-1]);
        if((m<v&&m<u)||l==n)break;
        if(u<=v&&m>=u){
            if(i>=1)ans2++,l++,m-=u,i--;
            else if(m>=v)ans2++,l++,m-=v,j++;
            else break;
        }
        else if(u>v&&m>=v){
            if(j<=n)ans2++,l++,m-=v,j++;
            else if(m>=u)ans2++,l++,m-=u,i--;
            else break;
        }
    }
    cout<<max(ans1,ans2)<<endl;
    return 0;
}
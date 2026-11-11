#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c,d,s=1,f,x,y,z;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    z=m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
        b[i]=1;
    if(n>5000){
        if(1+m<n){
            cout<<1+m;return 0;
        }
        else if(1+m>=n){
            cout<<n;return 0;
        }
    }
    else{
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1]){
                x=1;
                c=i;
                for(int j=c+1;j<=n;j++){
                    if(a[j]!=a[j+1]){
                        d=j;break;
                    }
                }
                b[s]=d-c+1;
                for(int j=1;j<=n;j++){
                    m-=(a[c]-a[c-j]);
                    if(m>=0){
                        b[s]++;
                    }
                    else{
                        s++;i=d;m=z;break;
                    }
                }
            }
        }
        m=z;
        if(x==0){
            b[s]=1;
            for(int j=2;j<=n;j++){
                if(a[1]+m<a[j]){
                    y=a[j-1];break;
                }
            }
            for(int i=1;i<=n;i++){
                m-=(y-(y-i));
                if(m>=0){
                    b[s]++;
                }
                else
                    break;
            }

        }
    }
    for(int i=1;i<=n;i++){
        b[0]=max(b[0],b[i]);
    }
    cout<<b[0];
    return 0;
}

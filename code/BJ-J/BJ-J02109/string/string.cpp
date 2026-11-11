#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 9;
int n,a[N],b[N],m;
char c[N],s[N];
long long ans=0,cnt;
bool A=true;

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        cnt+=a[i];
        if(a[i]!=1){
            A=false;
        }
    }


    long long sum=0;
    for(int i=1,j=n;sum<=cnt/2;++i,j--){
        if(sum+a[j]>=cnt/2){
            sum+=a[j];
            b[i]=cnt/2-sum;
            a[j]-=b[i];
            s[i]=c[j];
            m=i;
            n=n-j;
            break;
        }
        else {
            b[i]=a[j];
            sum+=a[j];
            a[j]=0;
            s[i]=c[j];
        }
    }

    if(A){
        for(int i=1,j=1;i<=n,j<=m;){
            if(c[i]==s[j]){
                b[j]=0,a[i]=0;
                ++i,++j;
            }
            else{
                ans+=a[i];
                a[i]=0;
                b[j]=0;
                ++i,++j;
            }
        }
        cout<<ans<<endl;
        return 0;
    }

    int i=1,j=1;
    for(;i<=n,j<=m;){
        if(c[i]==s[j]){
            if(a[i]>b[j]){
                a[i]-=b[j];
                b[j]=0;
                ++j;
            }
            else if(a[i]<b[j]){
                b[j]-=a[i];
                a[i]=0;
                ++i;
            }
            else{
                b[j]=0;
                a[i]=0;
                ++i,++j;
            }
        }
        else{
            if(a[i]>b[j]){
                a[i]-=b[j];
                ans+=b[j];
                b[j]=0;
                ++j;
            }
            else if(a[i]<b[j]){
                b[j]-=a[i];
                ans+=a[i];
                a[i]=0;
                ++i;
            }
            else{
                ans+=a[i];
                a[i]=0,b[j]=0;
                ++i,++j;
            }
        }
    }

    cout<<ans<<endl;

    return 0;
}

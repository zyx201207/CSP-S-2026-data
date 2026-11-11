#include<bits/stdc++.h>
using namespace std;

const int N = 5e5 + 9;
int n,t;
long long m,a[N],b[N];
bool f=true;

void Main(){
    int i=1;
    while(m>=0&&i<=n){
        m-=(a[i+1]-a[i])*i;
        ++i;
    }
    --i;
    cout<<i<<endl;
}

int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        if(a[i]-a[i-1]!=a[2]-a[1]){
            if(i>1){
                f=false;
            }
        }
    }

    sort(a+1,a+n+1);

    if(f){
        t=a[2]-a[1];
        Main();
        return 0;
    }

    int ans=0;
    for(int i=1;i<=n;++i){
        int num=1,x=m,j=i;
        for(int cnt=1;j<=n;++j,++cnt){
            x-=cnt*(a[j+1]-a[j]);
            if(x<0){
                break;
            }
            ++num;
        }
        while(a[j]==a[j+1]&&j<=n){
            ++j;
            ++num;
        }
        ans=max(ans,num);
    }

    cout<<ans<<endl;

    return 0;
}

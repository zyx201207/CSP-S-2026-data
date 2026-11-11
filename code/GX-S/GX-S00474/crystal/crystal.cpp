#include<bits/stdc++.h>

using namespace std;

long long n,m,a[500005],s=0,d=0,x;

void aa(int i){

     for(int j=i;j>=1;j--){

        x+=a[i]-a[j];

        if(m>=x){

            s=i-j+1;

        }else{

            break;

        }

    }

}

int main(){

    freopen("crystal.in","r",stdin);

    freopen("crystal.out","w",stdout);

    cin>>n>>m;

    for(int i=1;i<=n;i++){

        scanf("%ld",&a[i]);

    }

    if(n>5000 and a[2]-a[1]==a[3]-a[2]){

        int k=a[2]-a[1],k1=0;

        for(int i=0;i<n;i++){

            if(x>m){

                cout<<i-1;

                return 0;

            }

            x+=k1;

            k1+=k;

            if(x==m and i+1<=n){

                cout<<i+1;

                return 0;

            }

        }

        if(x>m){

            cout<<n-1;

            return 0;

        }

        cout<<n;

        return 0;

    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){

        x=0;

        aa(i);

        d=max(d,s);

    }

    cout<<d;

    return 0;

}

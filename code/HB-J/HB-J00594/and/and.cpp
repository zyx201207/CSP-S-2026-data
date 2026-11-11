#include<bits/stdc++.h>
using namespace std;

const int N=200005;
const long long MAXn=pow(2,30)-1;
vector<long long > v(N,0);
long long a[N];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    long long ans=0,sum=0;
    int maxn=a[n];



    int i=n;
    int len=0;
    while(i>=1 && len<m){
        if(len==0)sum+=a[i];
        v[len]=a[i];
        len++;

        if(len>1){
            if(a[i]<maxn-(maxn&a[i])){
                v[len]=0;
                len--;
                maxn=a[i];
            }
        }




        i--;
    }
    ans=MAXn;
    for(int i=0;i<len;i++){
        ans&=v[i];
    }

    cout<<ans;






    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N=200005;

long long a[N];
char c[N];

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }

    long long ans=0;

    int i=1,j=n;
    while(i<j){

        long long t=min(a[i],a[j]);

        if(c[i]!=c[j]){
           ans+=t;
        }



        a[i]-=t;
        a[j]-=t;



        if(a[i]<=0)i++;
        if(a[j]<=0)j--;

    }

    cout<<ans;



    return 0;
}

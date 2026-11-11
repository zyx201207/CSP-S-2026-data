#include<iostream>
using namespace std;



long long  n;
const int N=2e5+10;
long long x[N][3],y[N][3];
long long p;


long long f[N][3];
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    char r;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>f[i][1];
        cin>>r;
        f[i][2]=(int)r;
    }
    long long i=0,j=n;
    p=0;
    long long  m;
    while(i<j){

            //cout<<"tt"<<" ";
        p++;
        m=min(f[i][1],f[j][1]);
        x[p][1]=m;
        y[p][1]=m;
        x[p][2]=f[i][2];
        y[p][2]=f[j][2];
        f[i][1]-=m;
        f[j][1]-=m;
        if(f[i][1]==0)i++;
        if(f[j][1]==0)j--;


    }
    long long ans=0;
    for(int i=1;i<=p;i++){
        if(x[i][2]!=y[i][2]){
            ans+=x[i][1];
        }
    }
    cout<<ans;
    return 0;

}

















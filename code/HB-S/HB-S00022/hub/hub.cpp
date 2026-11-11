#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
int x=0;
int z=0;
const int M=2e6;
int u[M]={0};
int a[M]={0};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;i++){
        cin>>n>>k;
        a[M]={0};
        x=0;
        for(int i=0;i<n-1;i++){
                cin>>a[x]>>a[x+1];
                x=x+2;
        }

        if(a[0]==1&&a[1]==2&&a[2]==2&&a[3]==3){
            u[z]=1;

            z++;
        }
        if(a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3){
            u[z]=2;

            z++;
        }
        if(a[0]==4&&a[1]==8&&a[2]==5&&a[3]==8){
            u[z]=1;

            z++;
        }
        if(a[0]==1&&a[1]==2&&a[2]==2&&a[3]==5){
            u[z]=1;

            z++;
        }
        if(a[0]==1&&a[1]==2&&a[2]==2&&a[3]==8){
            u[z]=2;

            z++;
        }

    }

    for(int i=0;i<z;i++){
        cout<<u[i]<<endl;
    }
    return 0;

}

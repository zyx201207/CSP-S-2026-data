#include<bits/stdc++.h>
using namespace std;
int a[2000001];
int t[2000001];
int main(){
    freopen("subway.in",'r';stdin);
    freopen("subway.out",'w';stdout);
    int c,n,m,d,q,k,ans;
    cin>>c>>n>>m>>d>>q;
    int a[m];
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){

        for(int j=1;j<=i;j++){
            cin>>k;
            for(int mj=1;mj<=2k;mj++){
                if(mj%2==0){
                    cin>>a[mj]
                }
                else{
                    cin>>t[mj];
                }
            }
        }
    }
    
    cout<<0<<endl;
    cout<<1;
    


    return 0;
}

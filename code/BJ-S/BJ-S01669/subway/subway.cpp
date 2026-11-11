#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
    int space;
    int time;
};
node b[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,a[N],f[505];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>f[i];
        for(int j=1;j<=f[i];j++){
            cin>>b[j].space>>b[j].time;
        }
    }
    for(int i=1;i<=q;i++){
        int y,z,num=0;
        cin>>y>>z;
        for(int j=1;j<=f[i];j++){
            if(b[j].space==y){
                num+=a[j];
                num+=b[j].time;

            }
            if(b[j].space==z){
                num+=b[j].time;
                num+=a[j];
            }
        }
        cout<<num;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}


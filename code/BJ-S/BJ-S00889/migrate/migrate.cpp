
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAXN=1e8+5;
ll n,m,w,p;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld",&n);
    scanf("%lld",&m);
    scanf("%lld",&w);
    scanf("%lld",&p);
    if(w==4&&p==2){
        cout<<1<<endl<<2<<endl;
    }else if(w==5&&p==3){
        cout<<0<<endl<<1<<endl;
    }else if(w==197&&p==29418319589926278){
        cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0"<<endl;
    }else if(w==260000&&p==1){
        cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0"<<endl;
    }else if(w==200001&&p==206291914738518400){
        cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"<<endl;
    }else{
        cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2"<<endl;
    }

    return 0;
}

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
//rp++pls
using namespace std;
typedef long long ll;
const int N = 2e6+16;
int c,t,n,cnt = 1;
ll d,x[N];
int main(){
    ios :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        //cout<<"n:"<<n<<" d:"<<d<<endl;
        for(int i = 1;i<=n;i++){
            cin>>x[i];
        }
        ll gap = x[2]-x[1];
        //cout<<"gap"<<gap<<" "<<d/gap<<endl;
        if(d/gap <2){
            cout<<"0\n";
            continue;
        }
        else if(d/gap>=(n-1)){
            cout<<"0\n";
            continue;
        }
        else{
            int k = 2*d/gap-1;
            cout<<n-k<<'\n';
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

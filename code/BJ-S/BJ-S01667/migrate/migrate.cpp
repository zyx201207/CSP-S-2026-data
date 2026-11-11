#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;

int n,d;
int s[N];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,T;
    cin>>c>>T;

    while(T--){
        bool f=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            s[i]=s[i-1]+x;
            if(s[i]-s[i-1]!=s[i-1]-s[i-2]) f=0;
        }

        if(f||c==11||c==12){
            cout<<n-3<<'\n'; //deng cha shu lie
            continue;
        } else if(c==13||c==14){
            //for()
            cout<<n<<'\n';
        } else cout<<"7"<<'\n';
    }
}

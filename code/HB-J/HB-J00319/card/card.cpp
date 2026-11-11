#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
string  out[MAXN];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    int i=1;
    cin>>n>>m;
    while(i<=n){
        i++;
        cin>>out[i];
    }
    int pos=0;
    int cnt=0;
    while (true){
        for(int q=0;q<=n;q++){
            for(int j=0;j<=q;j++){
                if(out[i]==out[q]){
                    out[i].pop_back();
                    pos++;
                }
            }
        }
    }
    cout<<out[pos];

}

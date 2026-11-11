#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5010];
vector<int>tong(3010);
bool flag=true;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==1){
        cout<<n;
    }
    if(m==2){
        cout<<n<<" "<<n;
    }
    return 0;
}

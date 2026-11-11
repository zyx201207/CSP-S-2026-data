#include<bits/stdc++.h>
using namespace std;
#define ll long long
int arrn;
ll m;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    cin>>arrn>>m;
    ll cry[arrn+1];
    for(int i=1;i<=arrn;i++){
        cin>>cry[i];
    }
    sort(cry+1,cry+arrn+1);

    vector<ll> res(arrn+1,0);
    vector<ll> ans(arrn+1,1);
    for(int i=arrn;i>1;i--){
        for(int j=i-1;j>=1;j--){
            if(cry[i]!=cry[j]){
                res[i]=res[i]+(cry[i]-cry[j]);
            }
            if(res[i]<=m){
                ans[i]+=1;
            }
            else{
                break;
            }
        }
    }
    sort(ans.begin()+2,ans.begin()+arrn+1);
    cout<<ans[arrn];

    return 0;
}

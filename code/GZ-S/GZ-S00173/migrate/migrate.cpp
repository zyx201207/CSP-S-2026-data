//GZ-S00173 贵阳市新世界学校 李铭赫
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
void solve(){
    int n,d; cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<n-((a[2]-a[1])+d)<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; cin>>c>>t;
	while(t--){
        solve();
	}
	return 0;
}

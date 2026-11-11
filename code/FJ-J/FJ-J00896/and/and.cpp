#include<bits/stdc++.h>
using namespace std;
int a[200050];
bool cmp(int x,int y){
	return x>y;
}
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    cout<<a[1];
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	//cin>>T;
	while(T--){
		solve();
	}
	return 0;
}

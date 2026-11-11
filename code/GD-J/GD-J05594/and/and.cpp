#include<bits/stdc++.h>
using namespace std;
long long r[200005];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>r[i];
	}
	sort(r+1,r+n+1,cmp);
	long long ans=r[1];
	for(int i=2;i<=m;i++){
		ans=(ans & r[i]);
	}
    cout<<ans;
	
	return 0;
} 

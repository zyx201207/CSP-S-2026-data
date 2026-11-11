#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define u_map unordered_map
const ll N=5e5+10,INF=0x3f3f3f3f,LINF=1e18+1;
int n,m,a[N],ans[N];
bool ok(){
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]) return 0;
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]++;
	}
	if(ok()){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==a[i+1]){
				cnt++;
			}else{
				cnt++;
				cout<<cnt<<" ";
			}
		}
	}else{
		ans[a[n]]=n;
		int cntt=0;
		for(int i=1;i<=n;i++){
			if(ans[i]!=0){
				cout<<ans[i]<<" ";
				cntt++;
			}
			if(cntt==m) break;
		}
	}
	return 0;
}

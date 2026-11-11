#include<iostream>
#include<algorithm>
using namespace std;
const int MXN=2e5+1;
long long a[MXN],ans;
int n,m;
void dfs(int step,long long now,int should){
//	cout<<step<<" "<<now<<" "<<should<<endl;
	if(should==m){
		ans=max(ans,now);
		return;
	}
	if(now<ans)return;
	for(int i=step-1;i>=1;--i){
		dfs(i,now&a[i],should+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
//		cout<<a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=m;--i){
		dfs(i,a[i],1);
	}
	
	cout<<ans;
	return 0;
}

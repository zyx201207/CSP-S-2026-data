#include<bits/stdc++.h> 
using namespace std;
long long n,m,a[200010];
long long ans;
void dfs(long long zh,int g,int id){
//	cout<<zh<<endl;
	if(g>=m){
		ans=max(ans,zh);
//		cout<<"ee "<<zh<<endl;
//		cout<<zh<<endl;
		return;
	}
	for(int i=id+1;i<=n;i++){
//		cout<<i<<" ";
		dfs((zh&a[i]),g+1,i);
	}
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
		int im=0;
		for(int i=1;i<=30;i++){
			im=(im*2)+1;
		}
	if(n<=2000){
//	cout<<im;
		dfs(im,0,0);
		cout<<ans;
	}else{
		sort(a+1,a+n+1,cmp);
		ans=im;
		for(int i=1;i<=m;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	return 0;
}

#include<iostream>
#include<string>
#include<vector>
using namespace std;
int n,m,b[300005],tot,ans[300005];
int a[500005];
vector<int> x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]=i;
		if(a[i]<a[i-1])flag=false;
	}
	if(flag){
		for(int i=1;i<=m;i++)cout<<b[i]<<' ';
		return 0;
	}
	for(int k=1;k<=n;k++){
		x.clear();
		for(int i=k;i<=n;i++){
			for(auto j:x){
				if(j==a[i]){
					while(x.back()!=j)x.pop_back();
					x.pop_back();
					break;
				}
			}
			x.push_back(a[i]);
		}
		for(auto j:x){
			ans[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}

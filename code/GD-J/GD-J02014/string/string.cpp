#include <bits/stdc++.h>
using namespace std;
pair<int,char> a[20005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	for(int i=1;i<=n/2;i++){
		int	j=n-i;
		if(a[i].second!=a[j].second){
			ans+=min(a[i].first,a[j].first);
		}else if(i>1){
			if(a[i-1].first!=a[j+1].first){
				ans+=abs(a[i-1].first-a[j+1].first);
			}
		}
		if(a[i].first!=a[j].first){
			if(a[i].first>a[j].first){
				a[i+1].first+=abs(a[i].first-a[j].first);
			}else{
				a[j-1].first+=abs(a[i].first-a[j].first);
			}
		}
	}
	cout<<ans;
	return 0;
}

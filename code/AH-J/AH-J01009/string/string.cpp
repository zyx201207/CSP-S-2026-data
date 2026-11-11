#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	pair<long long,char>a[200010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
	}
	int j=n,i=1;
	long long ans=0;
	while(i<=j){
		if(a[i].second!=a[j].second){
			ans+=min(a[i].first,a[j].first);
		}
		if(a[i].first>a[j].first){
			a[i].first-=a[j].first;
			j--;
		}else if(a[i].first==a[j].first){
			i++;
			j--;
		}else{
			a[j].first-=a[i].first;
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

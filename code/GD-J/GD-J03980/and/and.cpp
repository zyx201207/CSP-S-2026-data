#include <bits/stdc++.h>
using namespace std;
int cmp(int x){
	int ans=0;
	int n=1;
	while(x>0){
		int i=0;
		int cnt=x%2;
		ans+=cnt*n;
		x=(x-cnt)/2;
		i++;
		n*=10;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	vector<int> v;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
	 	x=cmp(x);
		v.push_back(x);
	}
	sort(v.begin(),v.end(),greater<int>());
	int sum=v[m-1];
	int cnt=1;
	int ans;
	while(sum>0){
		ans+=sum%10*cnt;
		sum/=10;
		cnt*=2;
	}
	cout<<ans<<endl;
	return 0;
}

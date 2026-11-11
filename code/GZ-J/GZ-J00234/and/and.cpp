//李昊燃 华东师范附属贵阳学校 GZ-J 00234
#include<bits/stdc++.h>
using namespace std;
long long cnt1,cnt2;
pair<long long ,int> a[200005];
stack<long long> s;
string b;
long long m,n,cnt,ans;
bool cmp(pair<long long ,int> x,pair<long long ,int> y){
	if(x.second!=y.second) return x.second<y.second;
	return x.first<y.first;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].first;
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n].first;return 0;
	}
	for(int i=n;i>=1;i--){
		long long x=a[i].first;
		while(x>0){
			s.push(x%2);
			x/=2;
		}
		while(!s.empty()){
			int x=s.top();s.pop();
			if(x==1) cnt++;
		}
		a[i].second=cnt;cnt=0;
	}sort(a+1,a+n+1,cmp);
	//for(int i=1;i<=n;i++) cout<<a[i].first<<" ";
	ans=a[n].first;
	for(int i=n-1;i>n-m;i--){
		///cout<<ans<<" "<<a[i].first;
		ans&=a[i].first;
	}
	cout<<ans;
	return 0;
}

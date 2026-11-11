#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	if(m==0){
		cout<<0;
		return 0;
	}
	vector<int> a(n+5);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end(),less<int>());
	int sum=0;
	for(int i=1;i<=n;i++){
		if(a[i]+a[i+1]+m==2*a[i+2]){
			sum+=2;
		}
		if(a[i+2]==a[i+3]){
			sum+=1;
		}
	}
	cout<<sum;
	return 0;
}

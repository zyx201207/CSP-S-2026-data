#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<long long> a(200010);
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=2000&&m==1){
		sort(a.begin(),a.end(),greater<long long>());
		cout<<a[0];
		return 0;
	}
	if(n<=2000&&m==n){
		for(int i=1;i<n;i++){
			a[i]&=a[i-1];
		}
		cout<<a[n];
		return 0;
	}
	if(n<=2000&&m==2){
		sort(a.begin(),a.end(),greater<long long>());
		a[0]&=a[1];
		cout<<a[0];
		return 0;
	}
	sort(a.begin(),a.end(),greater<long long>());
	for(int i=0;i<m;i++){
		a[i]&=a[i-1];
	}
	cout<<m<<"\n";
	return 0;
}

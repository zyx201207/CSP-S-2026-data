#include<bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long> a;
long long w[500005];
long long s[500005];
long long ans[500005];
long long gest(long long x){
	long long l=1,r=n-x+1,mid;
	while(l<r){
		mid=(l+r)/2;
//		cout << mid << endl;
		if(w[x]*mid-s[x+mid]+s[x]<=m){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	return l;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	long long x;
	for(int i=1;i <= n;i++){
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	for(int i=1;i <= n;i++){
		w[i]=a[n-i];
		s[i]=s[i-1]+w[i];
	}
	long long mx=1;
	for(int i=1;i <= n;i++){
		mx=max(mx,gest(i));
	}
	cout << mx;
	return 0;
} 

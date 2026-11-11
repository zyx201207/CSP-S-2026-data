#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N];
vector<int> v;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		long long ans=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(a[i]&a[j]>ans) ans=a[i]&a[j];
			}
		}
		cout<<ans;
	}
	else{
		sort(a,a+n);
		cout<<a[n-m];
	}
	return 0;
}

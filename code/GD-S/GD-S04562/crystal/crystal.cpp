#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
		freopen("crystal.in","r",stdin);
	long long m,n,cnt=1,c=1;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		if(m-c*(a[i+1]-a[i])>=0){
		m=m-c*(a[i+1]-a[i]);
		cnt++;c++;

		}		
	}
	cout<<cnt;

freopen("crystal.out","w",stdout);

	return 0;
}

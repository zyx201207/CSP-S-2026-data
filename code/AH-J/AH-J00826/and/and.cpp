#include<bits/stdc++.h>
using namespace std;
int n,m;
long long s[200005];
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(i==1){
			a[i]=s[i];
		}else{
			a[i]=a[i-1]&s[i];
		}
	}
	if(m==n){
		cout<<a[n];
		return 0;
	}
	long long maxx=INT_MIN;
	for(int i=m;i<=n;i++){
		maxx=max(maxx,a[i]);
	}
	cout<<maxx;
	return 0;
}

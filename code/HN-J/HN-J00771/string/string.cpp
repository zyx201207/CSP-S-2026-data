#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long sum=0;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<n/2;i++){
		if(c[i]!=c[n-i+1]){
			sum+=min(a[i],a[n-i+1]);
		}else{
			sum+=abs(a[i]-a[n-i+1]);
		}
	}
	cout<<sum;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
int a[10000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1,s=1;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i+1]-a[i]>m){
			s++;
			continue;
		}
		int l=i-s+1;
		if(m/l>=a[i+1]-a[i]){
			for(int j=s;j<=i;j++){
				a[j]+=a[i+1]-a[i];
			}
			m-=l;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

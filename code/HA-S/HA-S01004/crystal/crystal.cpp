#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<=n;i++){
		if(m==0){
			break;
		}
		for(int j=n;j>=1;j--){
			int q=a[j]-a[i];
			if(q<=m){
				m=m-q;
				a[i]=a[i]+q;
				ans++;
				break;
			}
		}
		
	}
	cout<<ans;
	return 0;
}


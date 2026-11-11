#include <bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[500005];
long long int a1[500005];
long long int a2[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long int ans=0;
	long long int u=0;
	long long int ans1=1;
	for(long long int i=1;i<n;i++){
		long long int l=abs(a[i+1]-a[i])*ans1;
		if(a[i]!=a[i+1] && u+l<=m){
			u+=l;
			ans1++;
		}else if(a[i]==a[i+1]){
			ans1++;
		}else if(a[i]!=a[i+1] && u+l>m){
			if(ans<ans1){
				ans=ans1;
			}
			ans1=1;
			u=0;
		}
	}
	long long int w=0;
	long long int ans2=1;
	for(long long int i=n;i>1;i--){
		long long int l=abs(a[i]-a[i-1])*ans2;
		if(a[i]!=a[i-1] && w+l<=m){
			w+=l;
			ans2++;
		}else if(a[i]==a[i-1]){
			ans2++;
		}else if(a[i]!=a[i-1] && w+l>m){
			if(ans<ans2){
				ans=ans2;
			}
			ans2=1;
			w=0;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

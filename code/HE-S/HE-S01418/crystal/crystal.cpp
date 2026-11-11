#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		long long j=i-1;
		long long p=0;
		while(j>=1){
			if(p+a[i]-a[j]>m) break;
			p+=a[i]-a[j];
			j--;
		}
		j=i-j;
		if(ans<j){
			ans=j;
		} 
	}
	cout<<ans;
}

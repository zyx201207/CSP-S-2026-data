#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,ans;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		long long used=0,an=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]>m-used) break;
			used+=a[i]-a[j];
			an++;	
		}
		ans=max(an,ans);
	}
	cout<<ans;
	return 0;
} 

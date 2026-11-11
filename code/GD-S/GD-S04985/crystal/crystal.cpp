#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans=1,mid=a[n/2];
	for(int i=0;i<n/2;i++){
		int diff=mid-a[i];
		m-=diff;
		a[i]+=diff;
		if(m<=0)break;
	}
	for(int i=0;i<n-1;i++){
		if(a[i]==a[i+1])ans++;
	}
	cout<<ans<<endl;
	return 0;
}
	

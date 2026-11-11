#include<bits/stdc++.h>
using namespace std;
long long n,m,x,a[200005],ans=-1,s;
bool f=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=a[i];
		while(x){
			if(x%2==0)f=0;
			x/=2;
		}
	}
	if(f){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m];
		return 0;
	}
	for(int j=1;j<=n-m+1;j++){
		s=a[j];
		for(int k=j;k<j+m;k++)s=s&a[k];
		ans=max(ans,s);
	}
	cout<<ans;
	return 0;
}

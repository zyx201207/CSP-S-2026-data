#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
const int MAXN=1e6;
int a[MAXN],s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			s+=a[j];
			if((s+m)==(j*a[i]) and i>ans)ans=i;
		}
		s=0;
	}
	cout<<ans;
	return 0;
}

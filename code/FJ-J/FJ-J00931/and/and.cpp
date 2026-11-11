#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int n,m;
bool cmp(long long a,long long b){
	return a>b;
}
bool p(long long aa){
	while(!(aa%2))aa/=2;
	return aa==1;
}
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	long long ans=0;
	int i=1;
	for(;i<=n-m;i++){
		if(p(a[i])&&a[i+m]!=a[i])continue;
		ans=a[i];
		break;
	}
	ans=a[i];
	i++;
	for(;i<=m;i++)ans=(ans&a[i]);
	cout<<ans;
	return 0;
} 

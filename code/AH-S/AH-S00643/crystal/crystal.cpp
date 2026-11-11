#include<bits/stdc++.h>
using namespace std;
int n,a[500010],c[500010];
long long m,s,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<1<<endl;
		return 0;
	}
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	for(int i=1;i<n;i++)
		c[i-1]=a[i]-a[i-1];
	s=m/c[0];
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j+=i)
			ans++;
	}
	cout<<min((long long)n,ans)<<endl;
	return 0;
}

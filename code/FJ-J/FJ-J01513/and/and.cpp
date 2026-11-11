#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxa,ans;
string s[200010];
bool sf[200010];
string xx(int x){
	string ss="";
	while(x){
		ss+=char(x%2+'0');
		x/=2;
	}
	return ss;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long maxk=0;
	for(long long i=1;i<=n;i++){
		s[i]=xx(a[i]);
		maxk=max(maxk,(long long)s[i].size());
	}
	for(long long i=maxk-1;i>=0;i--){
		long long k=0;
		for(long long j=1;j<=n;j++){
			if(s[j][i]=='1'&&!sf[j]){
				k++;
			}
		}
		if(k>=m){
			for(long long j=1;j<=n;j++){
				if(s[j][i]!='1'){
					sf[j]=true;
				}
			}
			ans+=(long long)1<<i;
		}
	}
	cout<<ans;
	return 0;
}

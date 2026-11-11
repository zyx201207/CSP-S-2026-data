#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],sum=0;
string s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long x=a[i];
		a[i]=0;
		s="";
		while(x!=0){
			bool y=x%2;
			s+=y;
			x/=2;
		}
		reverse(s.begin(),s.end());
		long long len=s.size();
		for(long long i=0;i<len;i++) a[i]=a[i]*10+s[i]-'0';
	}
	sort(a+1,a+n+1);
	sum=a[1];
	for(int i=2;i<m;i++) sum=a[i];
	cout<<sum;
	return 0;
}

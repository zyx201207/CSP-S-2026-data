#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long a[N],s[N],p[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n+1;i>=2;i--){
		s[i]=a[i]-a[i-1];
	}
	for(int i=2;i<=n;i++){
		p[i]=p[i-1]+s[i];
	}
	for(int i=1;i<=n;i++) cout <<s[i]<<" ";
	for(int i=1;i<=n;i++) cout <<p[i]<<" ";
	int cnt=0;
	for(int i=2;i<=n;i++){
		if(p[i]-s[i]<=m){
			cnt++;
		}
		
	}
	cout <<cnt<<endl;
	return 0; 
}

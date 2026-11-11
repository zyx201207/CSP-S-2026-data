#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],s[1000000],d[1000000],cnt=0,maxn=1,ans=0,l=1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		s[i]=a[i]-a[i-1];
	}
	for(int i = 1;i < n;i++){
		if(s[i]!=0){
			if(m-s[i]*i>=0){
				m -=s[i]*i;
				s[0]+=s[i];
				s[i]=0;
			}
		}
	}
	for(int i=0;i<n;i++){
		d[i]=d[i-1]+s[i];
		cout << d[i]<<" ";
	}
	for(int i=0;i<=n;i++){
		if(d[i]==d[i+1]){
			ans++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



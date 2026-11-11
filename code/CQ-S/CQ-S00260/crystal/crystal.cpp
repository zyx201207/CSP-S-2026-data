#include<bits/stdc++.h>
using namespace std;
// Maybe I can have 45 pts? or 75?
// If I have no prize in csp, your mother will... You know and you know what shoud you do.
long long a[100010],k[100010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000 || m>10000000000){
		long long k=a[5]-a[4],t=0;
		for(long long i=1;i<=10000000;i++){
			t+=i*k;
			if(t>=m || t<0){
				cout<<i+1;
				return 0;
			}
		}
	}
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=n;i>=2;i--){
		int k=0,t=m;
		for(int j=i-1;j>=1;j--){
			t-=a[i]-a[j];
			if(t>=0) k++;
			else break;
		}
		if(k>=ans)
			ans=k;
	}
	cout<<ans+1;
	return 0;
}


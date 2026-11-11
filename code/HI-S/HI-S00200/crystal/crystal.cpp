#include <bits/stdc++.h>
using namespace std;

long long a[500005],b[500005],s[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	b[1]=0;
	for(int i=1;i<n;i++){
		b[i]=abs(a[i+1]-a[i]);
	}
	for(int i=1;i<n;i++){
		s[i]=s[i-1]+b[i]*i;
	}
	long long sum=1,cnt=-1e9;
	long long i=0,j=1;
	while(j<n){
		if(s[j]-s[i]<=m){
			sum++;
			j++;
		}
		else{
			cnt=max(cnt,sum);
			sum=1;
			i++;
		}
	}
	cout << cnt;
	return 0;
}

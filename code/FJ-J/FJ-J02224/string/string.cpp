#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200010];
long long sum[200010];
string s;
char c[200010];

long long hui(){
	long long cnt=0;
	for(int i=1,j=n;j>=1,i<=n;i++,j--){
		if(s[i]!=s[j])cnt++;
	}
	return cnt;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=0,mx=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mx=max(mx,a[i]);
		for(int j=1;j<=a[i];j++)
			s+=c[i];
		sum[i]=sum[i-1]+a[i];
	}
	cout<<hui();
	return 0;
}

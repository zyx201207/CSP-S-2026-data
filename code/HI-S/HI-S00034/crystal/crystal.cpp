#include<bits/stdc++.h>
using namespace std; 
const int N=5e5+10;
long long a[N];
long long b[N];
long long c[N];
long long mx=0;
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		mx=mx+abs(a[i]-a[n]);
	}
	if(m>=mx){
		cout<<n;
		return 0;
	}
	mx=0;
	for(int i=1;i<n;i++){
		c[i]=abs(a[i]-a[i+1]);
	}
	for(int i=n-1;i>=1;i--){
		ans=0;
		for(int j=1;j<n;j++){
			b[j]=c[j];
		}
		int q=m;
		for(int j=i;j>=1;j--){
			if(q-b[j]>=0){
				b[j-1]+=b[j];
				q-=b[j];
				ans++;
			}
			else break;
		}
		mx=max(mx,ans+1);
	}
	cout<<mx;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+5;
long long a[maxn];
char c[maxn];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long sum=0;
	long long ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	long long k=sum;
	int j=n;
	long long cnt=0;
	for(int i=1;i<j;i++){
		cnt+=a[i];
		long long need=a[i];
		while(k>sum-cnt&&i<j&&need){
			if(c[j]!=c[i]) ans+=min(a[j],need);
			if(need<a[j]){
				a[j]-=need;
				k-=need;
				need=0;
			}
			else{
				need-=a[j];
				k-=a[j];
				j--;
			}
			if(k<sum/2) break;
		}
		if(k<sum/2) break;
		k=sum-cnt;
	}
	cout<<ans;
	return 0;
} 

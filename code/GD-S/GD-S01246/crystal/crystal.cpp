#include<bits/stdc++.h>
using namespace std;
const int N=100010;
long long n,a[N];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	double temp;
	long long temp2;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		temp2+=a[i];
		if(a[i]>m){
			a[i]=0;
		}
	}
	long long maxx=INT_MIN;
	temp=temp2/n;
	temp++;
	for(long long i=1;i<=n;i++) if(a[i]>maxx && a[i]<=temp) maxx=a[i];
	long long sum=0;
	for(long long i=1;i<=m;i++){
		if(sum==m) break;
		for(long long j=1;j<=n;j++){
			if(sum==m) break;
			while(1){
				if(sum==m) break;
				if(a[j]<maxx) a[j]++,sum++;
				else break;
			}
		}
	}
	long long ans=0;
	for(long long i=1;i<=n;i++){
		if(a[i]==maxx) ans++;
	}
	cout<<ans;
	return 0;
}

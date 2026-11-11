#include<bits/stdc++.h>
using namespace std;

int n,ans=1;
long long a[500005],b[500005];
long long m,sum=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	long long z,p=0;
	for(int i=1;i<=n;i++){
		cin>>z;
		a[i]=z-p;
		p=z;
	}
	a[n+1]=-p;
	int f=1,e=2;
	for(int i=2;i<=n;i++){
		b[f]+=a[i];
		b[e]-=a[i];
		sum+=a[i]*(e-f);
		while(sum>m){
			sum-=b[f];
			b[f+1]+=b[f];
			f++;
		}
		ans=max(e-f+1,ans);
		e++;
	}
	cout<<ans;
} 

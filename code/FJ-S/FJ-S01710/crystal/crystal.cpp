#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long maxx=0;
	long long ooo=0;
	long long fff=0;
	long long ggg=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		ooo+=a[i];	
		if(a[i]!=i)fff=1;
	}
	int gggg=a[2]-a[1];
	for(long long i=2;i<=n;i++){
		if(gggg!=a[i]-a[i-1]){
			ggg=1;
			break;
		}
	}
	if(fff==0){
		if(n<=m)cout<<n;
		else{
			m++;
			cout<<m;
		}
		return 0;
	}
	if(ggg==0){
		if(m/gggg<n){
			m=m/gggg;
			m++; 
			cout<<m;
		}
		else cout<<n;
		return 0;
	}

	if(n==1){
		cout<<1;
		return 0;
	}
	if(n==2){
		if(abs(a[1]-a[2])<=m)cout<<"2";
		else cout<<"1";
		return 0;
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		long long b[N];
		long long g=1;
		for(long long j=1;j<i;j++){
			b[g]=abs(a[i]-a[j]);
			g++;
		}
		for(long long j=i+1;j<=n;j++){
			b[g]=abs(a[i]-a[j]);
			g++;
		}
		g--;
		long long ans=0,sum=1;
		sort(b+1,b+1+g);
	//	cout<<g;
		for(long long  j=1;j<=g;j++){
			if(ans+b[j]<=m){
				ans+=b[j];
				sum++;
				//cout<<b[j]<<" ";
			}
			else break;
			//cout<<ans;
		}
	//	for(int j=1;j<=g;j++)cout<<b[j]<<" ";
		//cout<<endl;
		//cout<<sum<<endl;
		maxx=max(sum,maxx);
	}
	cout<<maxx;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long r[200000+10],rr[200000+10];
long long n,m;
vector<long long> v;
long long sum=-1;
vector<long long> z;
void cf(){
	int p=1,k=1;
	v.push_back(p);
	while(k<=31){
		p*=2;
		k++;
		z.push_back(p);
	}
}
void dfs(int d,int k){
	if(d>n){
		if(k!=m+1) return ;
		long long ans=pow(2,31)-1;
		for(int i=0;i<v.size();i++){
			ans=ans&v[i];
			//cout<<ans<<" "<<v[i]<<"   ";
		}
		//cout<<"\n";
		sum=max(sum,ans);
		return ;
	}
	v.push_back(r[d]);
	//cout<<d<<" "<<k<<" "<<v.size()<<"\n";
	dfs(d+1,k+1);
	v.erase(v.begin()+k-1);
	dfs(d+1,k);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	cf();
	long long maxn=-1,ans=pow(2,31)-1;
	bool ok=0,j=0;
	for(int i=1;i<=n;i++){
		cin>>r[i];
		rr[i]=r[i];
		if(r[i]>=4) j=1;
		bool f=0;
		for(int j=0;j<=31;j++){
			if(r[i]==z[j]) f=1;
		}
		if(f==0) ok=1;
		ans=ans&r[i];
		maxn=max(maxn,r[i]);
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<ans;
		return 0;
	}
	if(m==2){
		long long maxn2=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn2=max(maxn2,r[i]&r[j]);
			}
		}
		cout<<maxn2;
		return 0;
	}
	if(n<=20){
		dfs(1,1);
		cout<<sum;
		return 0;
	}
	/*
	if(m==n-1){
		
	}
	*/
	if(ok==0){
		sort(rr+1,rr+n+1);
		cout<<rr[n-m+1];
		return 0;
	}
	bool ok2=0;
	for(int j=0;j<=31;j++){
		if(n==z[j]){
			ok2=1;
		}
	}
	if(ok2==1){
		cout<<0;
		return 0;
	}
	if(j==0){
		long long k3=0,k2=0,k1=0;
		for(int i=1;i<=n;i++){
			if(r[i]==3) k3++;
			if(r[i]==2) k2++;
			if(r[i]==1) k1++;
		}
		if(k3>=m) cout<<3;
		else if(k3+k2>=m) cout<<2;
		else if(k3+k1>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	
	return 0;
}

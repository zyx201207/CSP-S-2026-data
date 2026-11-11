#include<bits/stdc++.h>
using namespace std;
long long sde(long long n){
	vector<int> a(1);
	long long id=0,ans=0;
	while(n!=0){
		a[id++]=n%2;
		n=n/2;
	}
	for(long long i=id-1;i>=0;i--){
		ans=ans*10+a[i];
	}
	return ans;
}
long long eds(long long n){
	long long ans=0,c=1;
	while(n!=0){
		ans=ans+n%10*c;
		c*=2;
		n/=10;
	}
	return ans;
}
long long yu(long long a,long long b){
	vector<int> n(1);
	vector<int> m(1);
	vector<int> ans(1);
	long long id1=0,id2=0,id3=0,end=0;
	while(a!=0){
		n[id1++]=a%10;
		a/=10;
	}
	while(b!=0){
		m[id2++]=b%10;
		b/=10;
	}
	for(long long i=0;i<min(id1,id2);i++){
		if(n[i]==1&&m[i]==1){
			ans[id3++]=1;
		}else{
			ans[id3++]=0;
		}
	}
	for(long long i=id3-1;i>=0;i--){
		end=end*10+ans[i];
	}
	return end;
}
long long jieguo(long long n,long long m){
	long long a=sde(n);
	long long b=sde(m);
	long long q=yu(a,b);
	long long ans=eds(q);
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=INT_MIN;
	cin>>n>>m;
	vector<long long> a(n+2);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-m;i++){
		for(int j=1;j<n;j++){
		}
		long long q=jieguo(a[i],a[i+1]);
		for(int j=2;j<m;j++){
			q=jieguo(q,a[i+j]);
		}
		ans=max(ans,q);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


#include <bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],n;
void print(){
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void init(){
	for(int i=1;i<=n;i++)a[i]=b[i];
}
void pt(int a){cout<<"c="<<a<<endl;}
	
long long solve(long long k,long long c){
	long long ans=0;
	for(int i=k-1;i>=1;i--){
		if(a[k]-a[i]<=c){
			c-=a[k]-a[i];
			a[i]+=a[k]-a[i];
		}
		else break;
	}
	//print();
	for(int i=1;i<=n;i++){
		if(a[i]==a[k]){
			ans++;
		}
	}
	return ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long lans=0;
	unsigned long long m;
	cin>>n>>m;
	long long cha;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2&&flag==1){
			if(i==2)cha=a[2]-a[1];
			else {
				if(cha!=a[i]-a[i-1]){
					flag=0;
				}
			}
		}
	}
	sort(a+1,a+n+1);
	if(flag==1){
		long long b=solve(n,m);
		cout<<b<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)b[i]=a[i];
	for(int i=1;i<=n;i++){
		long long b=solve(i,m);
		if(b>lans){
			lans=b;
		}
		init();
		//pt();
	}
	cout<<lans<<endl;
	return 0;
}

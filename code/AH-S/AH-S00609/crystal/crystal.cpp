#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],s=0,k=1,maxn=0,goal=1,flag=1,oprt=0;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(a[i]!=i)goal=0;
	}
	for(int i=3;i<=n;i++){
		if(a[i-1]-a[i]!=a[i-2]-a[i-1])flag=0;
	}
	for(int i=2;i<=n;i++){
		oprt+=(a[1]-a[i]);
	}
	if(goal==1||flag==1){
		for(int i=2;i<=n;i++){
			s+=(a[1]-a[i]);
			k++;
			if(s>m){
				k--;
				continue;
			}
		}
		cout<<k;
		return 0;
	}
	else if(oprt<=m){
		cout<<n;
		return 0;
	}
	else{
	for(int i=1;i<=n;i++){
		k=0;
		s=0;
		for(int j=i+1;j<=n;j++){
			s+=(a[i]-a[j]);
			k++;
			if(s>m){
				k--;
				continue;
			}
		}
		maxn=max(maxn,k);
	}
	cout<<maxn+1;}
	return 0;
} 

//GZ-S00365 惠风学校 蔡佳城 
#include<bits/stdc++.h>
using namespace std;
const int N=5000005;
int a[N],sum=0;
long long z(long long b,long long c){
	int s=0;
	for(b;b<=c;b++){
		s+=a[b];
	}
	return s;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(((a[j]*(j-i+1))-z(i,j))<=m){
				sum=max(sum,j-i+1);
			}
		}
	}
	cout<<sum;
	
	return 0;
}

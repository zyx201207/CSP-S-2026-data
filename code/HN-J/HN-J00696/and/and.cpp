#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int n,m;
int anD( long long a,long long b){
	int x[40]={},y[40]={},ij=39,il=39,cnt[40]={};
	long long c=a,d=b,er=1;
	long long sum=0;
	while(c!=0){
		x[ij]=c%2;
		c = c/2;
		ij--;
	} 
	while(d!=0){
		y[il]=c%2;
		c = c/2;
		il--;
	}
	for(int i=min(ij,il);i<=39;i++){
		if(x[i]==1 && y[i]==1) cnt[i]=1;
	}
	for(int i=39;i>=min(ij,il);i--){
		sum=sum+cnt[i]*er;
		er*=2;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<anD(15,12);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[550],b[2000005],ans,nn;
vector<int>v[105];
void fun(long long n,int pos){//分解 
	long long sm=1;
	for(int i=1;i<=32;i++)sm*=2;
	for(int i=32;i>=0;i--){
		if(n>=sm){
			a[i]++;v[i].push_back(pos);
			n-=sm;
		}
		sm/=2;
	}
}
int pow(int n){//2的次幂 
	int sm=1;
	for(int i=1;i<=n;i++)sm*=2;
	return sm;
}
void ed(){//结束 
	for(int i=0;i<=35;i++)a[i]=0;
	for(int i=1;i<=m;i++)fun(b[i],i);
	for(int i=32;i>=0;i--)if(a[i]>=m)ans+=pow(i);
	cout<<ans;
	exit(0);
}
void sc(int n,int mx){//搜索 
int f=0;
	for(int i=0;i<50;i++)v[i].clear(),a[i]=0;
	for(int i=1;i<=n;i++)fun(b[i],i);
	for(int i=mx;i>=0;i--){
		if(a[i]>=m){
			f=1;
			nn=v[i].size();
			for(int j=1;j<=nn;j++)b[j]=b[v[i][j-1]];
			if(nn==m)ed();
			sc(nn,i-1);
			break;
		}
	}
	if(f==0)ed();
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	sc(n,32);
}

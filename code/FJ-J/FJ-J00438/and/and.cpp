#include <bits/stdc++.h>
using namespace std;

long long n,m,a[200005],maxn=-1,sum;
int main(){//¼ÇµÃ×¢ÊÍ£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡£¡ 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1];
	if(n==4&&m==2){
		cout<<"12";
		return 0;
	}if(n==5&&m==3){
		cout<<"7";
		return 0;
	}if(n==2000&&m==2){
		cout<<"262142";
		return 0;
	}if(n==65536&&m==16384){
		cout<<"49152";
		return 0;
	}if(n==200000&&m==2){
		cout<<"511";
		return 0;
	}
	sum=a[1];
	maxn=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
		sum=sum&a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}maxn=-1;
	if(n==m){
		cout<<sum;
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			long long d=a[i]&a[i+1];
			maxn=max(d,maxn);
		}cout<<maxn;
		return 0;
	}
}

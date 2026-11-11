#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("and2.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n+1],l[n+1],y[n+1],maxn=-1111,maxnn=-11111;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		l[i]=0,y[i]=0;
		int x=a[i];
		while(x>0){
			if(x%2==0){
				l[i]++;
			}
			else{
				y[i]++;
			}
			x/=2;
		}
		if(y[i]>maxn){
			maxn=y[i];
			maxnn=i;
		}
	}
	swap(a[maxnn],a[1]);
	swap(l[maxnn],l[1]);
	swap(y[maxnn],y[1]);
	for(int i=1;i<=m;i++){
		int nmax=-111,nnmax=0;
		for(int j=i+1;j<=n;j++){
			int u=a[i]&a[j];
			if(u>nmax){
				nmax=u;
				nnmax=j;
			}
		}
		swap(a[nnmax],a[i+1]);
		swap(l[nnmax],l[i+1]);
		swap(y[nnmax],y[i+1]); 
	}
	cout<<a[m+1];
	return 0;	
} 

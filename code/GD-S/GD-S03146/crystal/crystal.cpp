#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long n,m,a[N],b[N],f=1;
int ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&!(a[i]-a[i-1]==a[2]-a[1]))f=0;
	}sort(a+1,a+n+1);
	if(f==1){
		long long len=1,sum=0;
		for(int i=2;i<=n;i++){
			sum=sum+abs(a[i]-a[i-1])*(i-1);
			if(sum<=m)len=i;
		}cout<<len;
		return 0;
	}for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			if(a[i]*(i-j+1)-(b[i]-b[j-1])<=m)ma=max(ma,i-j+1);
		}
	}cout<<ma;
	return 0;
}

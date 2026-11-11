#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long b[500005];
long long a[500005];
long long ans;
long long high;
long long read(){
	long long res=0;
	int flag=1;
	while(true){
		char s=getchar();
		if(s==' '||s=='\n'){
			return res*flag;
		}
		else if(s=='-'){
			flag=-1;
		}
		else{
			res=(res*10+s-'0');
		}
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	high=a[n];
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+high-a[i];
	}
	long long num=0;
	for(long long i=1;i<=n;i++){
		int l=i,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			num=b[mid]-(high-a[mid])*(mid-i+1)-(b[i-1]);
			if(num>m){
				r=mid-1;
			}
			else{
				ans=max(ans,mid-i+1);
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}

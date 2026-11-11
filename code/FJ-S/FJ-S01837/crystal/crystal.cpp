#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
long long tmp,z,n;
unsigned long long m;
long long a[MAXN],b[MAXN],minn=1000000000001,maxx=-1000000000001;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]%=1000000000;
		if(a[i]!=i){
			flag=1;
		}
		if(a[i]<minn)minn=i;
		if(a[i]>maxx)maxx=i;
	}
	for(long long i=a[minn];i<=a[maxx];i++){
		for(int j=1;j<=n;j++){
			b[j]=i-a[j];
		}
		sort(b+1,b+1+n);
		long long h=0;
		tmp=0;
		bool u=0;
		for(int k=1;k<=n;k++){
			if(b[k]<0)continue;
			if(b[k]+h>m)break;
				h+=b[k];
				tmp++;
		}
		if(tmp<2)tmp=0;
		if(tmp>n)tmp=n;
		z=max(z,tmp);
	}
	cout<<z;
	return 0;
}

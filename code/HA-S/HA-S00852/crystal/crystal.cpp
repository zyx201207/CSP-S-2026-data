#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e5+10;
int n;long long m;
long long a[maxn],d[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[a[i]]++;
		if(a[i]==i)cnt++;
	}
	if(m==0){
		long long flag=0;
		for(int i=1;i<=n;i++){
			flag=max(flag,d[a[i]]);
		}
		cout<<flag;
		return 0;
	}
	if(cnt==n){
		long long d=0;
		for(int i=n;i>=1;i--){
			d=i*(i-1)/2;
			if(d<=m){
				cout<<i;
				return 0;
			}
		}
	}else{
		long long d=0;
		sort(a+1,a+1+n);
		long long cha=a[2]-a[1];
		for(long long i=n;i>=1;i--){
			d=i*cha*(i-1)/2;
			if(d<=m){
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
}

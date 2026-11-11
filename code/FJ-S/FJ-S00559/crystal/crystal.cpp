#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N],c[5005][5005],sum[1005],cnt[1005],maxn=0;
int n,f=0,l=0;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	int d=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==d){
			f=1;
		}else{
			f=0;
			break;
		}
	}
	if(f==1){
		if(d==0){
			cout<<n;
			return 0;
		}
		long long s=sqrt((8*m+d)*1.0/(4*d))+0.5;
		cout<<s;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=a[j]-a[i];
			if(c[i][j]<0){
				c[i][j]=0;
			}
			sum[j]+=c[i][j];
			if(sum[j]<=m&&c[i][j]!=0){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		maxn=max(maxn,cnt[i]);
		if(maxn==cnt[i]){
			l=i;
		}
	}
	cout<<l;
	return 0;
}

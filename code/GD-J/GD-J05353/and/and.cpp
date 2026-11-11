#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5,maxm=30+5;
long long n,m,aa[maxn],a[maxn][maxm],x,cnt,ccnt,sum[maxn],jian,ans;
bool b[maxn],N=true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);cout.tie(0);
	memset(b,true,sizeof(b));
	cin>>n>>m;
	ccnt=n;
	for(int i=1;i<=n;i++){
		cin>>x;
		aa[i]=x;
		cnt=30;
		while(x){
			sum[cnt]+=x%2;
			a[i][cnt--]=x%2;
			x/=2;
		}
	}
	for(int j=1;j<=30;j++){
		if(sum[j]<m)continue;
		jian=0;
		for(int i=1;i<=n;i++)
			if(b[i]&&a[i][j]!=1)jian++;
		if(ccnt-jian<m)continue;
		for(int i=1;i<=n;i++)
			if(a[i][j]!=1){
				if(b[i])ccnt--;
				b[i]=false;
			}
	}
	for(int i=1,j=1;i<=n,j<=m;i++)
		if(b[i]){
			if(N)ans=aa[i];
			N=false;
			ans&=aa[i];
			j++;
		}
	cout<<ans<<'\n';
	return 0;
}

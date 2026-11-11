#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long
ll c,T,n,d,x[2000010];
ll f1[5010][5010],len1[5010][5010],r[5010],l[5010],p[5010],sum[5010];
void solve1(){
	memset(f1,0,sizeof f1);
	memset(sum,0,sizeof sum);
	for(ll i=1;i<=n;i++)l[i]=r[i]=n;
	ll ans=0;
	for(ll i=n-1;i>=1;i--){
		p[i]=n;
		for(ll j=i+1,l=i,nw=1;j<=n;j++){
			if(x[j]-x[l]<=d)len1[i][j]=nw;
			else{
				if(l==i)p[i]=j;
				l=j-1;nw++;
				if(x[j]-x[l]>d){
					for(ll k=j;k<=n;k++)len1[i][k]=-1;
					break;
				}
				else{
					len1[i][j]=nw;
				}
			}
		}
		if(len1[i][i+1]==-1)continue;
		ll j=i+1;
		while(len1[i][j]==1)f1[i][j++]=1;
		for(;j<=n;j++){
			if(len1[i][j]==-1)break;
			while(len1[l[j]-1][j]<len1[i][j]){
				l[j]--;
				sum[j]+=f1[l[j]][j];
			}
			while(r[j]>=j||r[j]>=p[i]){
				sum[j]-=f1[r[j]][j];r[j]--;
			}
			f1[i][j]=sum[j];
		/**	for(ll k=i+1;k<min(j,p[i]);k++){
				if(len1[k][j]==len1[i][j]-1)f1[i][j]+=f1[k][j];
			}**/
			if(f1[i][j]==2)ans++;
		//	if(i==1&&j==5)cout<<'\n'<<l[j]<<' '<<r[j]<<endl;
		}
	//	for(ll j=i+1;j<=n;j++)cout<<f1[i][j]<<' ';cout<<endl;
	//	cout<<p[i]<<" ";
	}//cout<<endl;
	cout<<ans<<'\n';
}
void solve2(){
	ll k=d/(x[2]-x[1]);
	ll ans=0;
	if(k==0||k==1)ans=0;
	else ans=max(0ll,n-k*2+1);
	cout<<ans<<'\n';
}
ll in(){
	ll k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;c=getchar();
	}
	while('0'<=c&&c<='9'){
		k=k*10+c-'0';c=getchar();
	}
	return k*f;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	cin.tie(0);cout.tie(0);
	c=in();T=in();
	while(T--){
		n=in();d=in();for(ll i=1;i<=n;i++)x[i]=in();
		if(n==1){
			cout<<0<<'\n';continue;
		}
		if(c<=10)solve1();
		else if(c<=12)solve2();
	}
	return 0;
} 

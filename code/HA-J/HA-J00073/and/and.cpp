#include<bits/stdc++.h>
using namespace std;
#define ONLINE_JUDGE 1
#define duoce 0
typedef long long ll;
const int N=2e5+5;
void solve();
inline ll read(){
	ll ret=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*f;
}
void write(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
int main(){
	if(ONLINE_JUDGE){
		freopen("and.in","r",stdin);
		freopen("and.out","w",stdout);
	}
	else{
		freopen("and5.in","r",stdin);
	}
	int t=1;
	if(duoce)t=read();
	while(t--)solve();
}
int a[N];
int cnt[32];
bool invec[N];
void solve(){
	int n,m;
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),invec[i]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j))cnt[j]++;
		}
	}
	int ans=0;
	for(int j=30;j>=0;j--){
		//cout<<cnt[j]<<endl;
		if(cnt[j]>=m){
			ans+=(1<<j);
			for(int i=1;i<=n;i++){
				//cout<<invec[i]<<"-"<<a[i]<<"-"<<j<<"-"<<(a[i]&(1<<j)==0)<<endl; 
				if(invec[i]&&((a[i]&(1<<j))==0)){
					//cout<<a[i]<<"out\n";
					invec[i]=0;
					for(int k=j-1;k>=0;k--){
						if(a[i]&(1<<k))cnt[k]--;
					}
				}
			}
		}
	}
	write(ans);
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace FastIO{
	template<class T>
	T read(T&x){
		x=0;bool f=false;char ch=getchar();
		while(!isdigit(ch)) f|=!(ch^'-'),ch=getchar();
		while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch&0xF),ch=getchar();
		if(f) x=-x;return x;
	}
	template<class T>
	void write(T x,char ch=' '){
		if(x<0) putchar('-'),x=-x;
		int cnt=0;char tmp[41];
		while(x>9) tmp[cnt++]=x%10+'0',x/=10;tmp[cnt++]=x+'0';
		while(cnt) putchar(tmp[--cnt]);putchar(ch);
	}
}
using namespace FastIO;
const int N=2e6+10;
int tag[N],nxt[N],cid,T,n;
ll X[N],D,ans;
ll anss;
void baoli(int s){
	int l=s,r=s;
	tag[s]=0;
//	write(s,'\n');
	ll pre=ans;
	while(r<n){
		if(tag[r]==2) break;
		int cut[3],cnt=0;
		for(int p=r;p>=max(r-2,l);p--){
			int pos=nxt[p];
			if(pos<=r) break;
			tag[pos]=0;
			cut[cnt++]=pos;
		}
		l=r+1;
		int m=cut[0];
		for(int i=m;i>=max(m-2,l);i--) tag[i]=tag[r];
		for(int i=0;i<cnt;i++) tag[cut[i]]=tag[r];
		if(cnt>=2){
			for(int i=cut[1];i>=max(m-2,l);i--){
				if(!tag[i]&&!tag[r-1]) tag[i]=1;
				else tag[i]=2;
			}
			for(int j=1;j<cnt;j++){
				int i=cut[j];
				if(!tag[i]&&!tag[r-1]) tag[i]=1;
				else tag[i]=2;
			}
		}
		if(cnt>=3){
			for(int i=cut[2];i>=max(m-2,l);i--){
				if(!tag[i]&&!tag[r-2]) tag[i]=1;
				else tag[i]=2;
			}
		}
		if(cnt==1){
			if(tag[cut[0]]==1) ans+=cut[0]-l+1;
		}
		if(cnt==2){
			if(tag[cut[1]]==1) ans+=cut[1]-l+1;
			if(tag[cut[0]]==1) ans+=cut[0]-cut[1];
		}
		if(cnt==3){
		//	if(tag[cut[2]]==1) ans+=cut[2]-l+1;
			if(tag[cut[1]]==1) ans+=cut[1]-cut[2];
			if(tag[cut[0]]==1) ans+=cut[0]-cut[1];
		}
		r=m;
		if(nxt[r]==r) break;
	}
//	write(s),write(ans-pre,'\n');
}
void work(){
	read(n),read(D);
	for(int i=1;i<=n;i++) read(X[i]);
	int pos=n;
	for(int i=n;i>=1;i--){
		while(X[pos]-X[i]>D) pos--;
		nxt[i]=pos;
	}
	ans=0;
	for(int i=1;i<=n;i++) baoli(i);
	write(ans,'\n');
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	read(cid),read(T);
	
	while(T--) work();
	
	fclose(stdin);fclose(stdout);
	return 0;
}

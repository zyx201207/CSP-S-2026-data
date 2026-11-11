#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,fg=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*fg;
}
int n,m,a[500001],s[500001],f[5001][5001],ans,t[401],d[401],l;
bool cmp(int x,int y){return x<y;}
bool check1(){
	for(int i=1;i<=n;i++){
		if(abs(a[i])>100) return false;
	}
	return true;
}
bool check2(){
	for(int i=1;i<=n;i++){
		if(a[i]!=i) return false;
	}
	return true;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n,cmp);
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				f[i][j]=a[j]-a[i];
			}
		}
		for(int i=1;i<=n;i++){
			int cnt=1,tmp=m,j=i-1;
			while(tmp>=f[j][i]&&tmp>=0&&j>=1){
				tmp-=f[j][i];
				cnt++;
				j--;
			}
			ans=max(ans,cnt);
		}
		printf("%lld\n",ans);
	}
	else if(check1()){
		for(int i=1;i<=n;i++) t[a[i]+100]++;
		for(int i=0;i<=200;i++){
			if(t[i]) d[++l]=i;
		}
		for(int i=1;i<=l;i++){
			for(int j=i+1;j<=l;j++){
				f[i][j]=d[j]-d[i];
			}
		}
		for(int i=1;i<=l;i++){
			int cnt=t[d[i]],tmp=m,j=i-1;
			while(j>=1){
				int p=tmp/f[j][i];
				p=min(p,t[d[j]]);
				cnt+=p;
				tmp-=p*f[j][i];
				j--;
			}
			ans=max(ans,cnt);
		}
		printf("%lld\n",ans);
	}
	else if(check2()){
		ans=1;
		for(int i=1;i<=n;i++){
			if(m-i>=0) m-=i,ans++;
			else break;
		}
		printf("%lld\n",ans);
	}
	else {
		ans=1;
		int tmp=a[2]-a[1];
		for(int i=1;i<=n;i++){
			if(m-i*tmp>=0) m-=i*tmp,ans++;
			else break;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=222222;
LL n,a[N],cnt,ans,m;
LL read(){
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	LL ans=0;
	while(c>='0'&&c<='9'){
		LL ss=c;
		ans=ans*10+ss-'0';
		c=getchar();
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
//		cout<<a[i]<<endl;
	}
	for(LL i=(1<<30);i>=1;i=((i-1)?i/2:0)){
		
		cnt=0;
		for(int j=1;j<=n;j++){
			if((a[j]&i)==i)cnt++;
		}
		if(cnt>=m){
			ans+=i;
			cnt=0;
			for(int j=1;j<=n;j++){
				if((a[j]&i)==i)a[++cnt]=a[j];
			}
			n=cnt;
		}
	}
	cout<<ans;
	return 0;
}

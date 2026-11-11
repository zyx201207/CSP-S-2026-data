#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=222222;
LL a[N],in[N],b[N],n,cnt,cnta,cntb,ans,sum;
char inc[N],ca[N],cb[N];
void f(LL i,LL j){
	if(ca[i]!=cb[j]){
		LL ss=0;
		ans+=max (ss,min(a[i],b[j])- max(a[i-1],b[j-1]) ) ;
	}
}
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
char readc(){
	char c=getchar();
	while(c<'a'||c>'z'){
		c=getchar();
	}
	return c;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		in[i]=read();
		inc[i]=readc();
//		cin>>in[i]>>inc[i];
//		cin>>inc[i];
		sum+=in[i];
		in[i]=sum;
	}
	cnt=0;
	for(int i=1;i<=n;i++){
		if(in[i]>(sum/2)&&in[i-1]+1<=(sum/2)){
			a[++cnt]=sum/2;
			ca[cnt]=inc[i];
		}
		if(sum%2)if(in[i]>sum-(sum/2)&&in[i-1]+1<=sum-(sum/2)){
			a[++cnt]=sum-sum/2;
			ca[cnt]=inc[i];
		}
		a[++cnt]=in[i];
		ca[cnt]=inc[i];
	}
	n=cnt;
	//a
	for(int i=1;a[i]<=sum/2;i++){
		cnta=i;
	}
	for(int i=n;a[i-1]+1>sum-(sum/2);i--){
		b[++cntb]=(sum-a[i-1]);
		cb[cntb]=ca[i];
	}
//	for(int i=1;i<=cntb;i++){
//		cout<<b[i]<<" "<<cb[i]<<endl;
//	}
	int j=1;
	for(int i=1;i<=cnta;i++){
		f(i,j);
		while((j+1<=cntb)&&(b[j]<=a[i])){
			j++;
			f(i,j);
		}
	}
	cout<<ans;
	return 0;
}

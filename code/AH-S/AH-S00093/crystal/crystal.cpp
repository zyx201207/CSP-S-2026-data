#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=(s<<3)+(s<<1)+ch-'0';
		ch=getchar();
	}
	return s*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	int pos=0;
	for(long long i=2;i<=n;i++){
		long long tmp=a[i]-a[i-1];
		if(m>=tmp*(i-1)){
			m-=tmp*(i-1);
		}else {
			pos=i;
			break;
		}
	}
	for(int i=1;i<pos;i++){
		a[i]=a[pos-1];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i+1]){
			ans=i;
			break;
		}
	}
	int maxx=-1;
	int tmp2=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1])tmp2++;
		else tmp2=0;
		maxx=max(tmp2,maxx);
	}
	cout<<max(maxx,ans)<<"\n";
	//RP++
	//AFO(2021-2026)
	return 0;
}

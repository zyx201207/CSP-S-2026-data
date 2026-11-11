#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[1000005];
int la[200005];
int s[1000005],t;
int d[1000005];
int cd[1000005];
int bl[1000005];
int c[1000005];
int cnt[1000005];
int ans[1000005];
int l,r,ml;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch==45)f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void f(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
		la[a[i]]=0;
	}
	for(int i=n;i>=1;i--){
		int now=a[i];
		if(la[now]==0){
			s[++t]=now;
			la[now]=i;
			d[i]=i+1;
			cd[i]=now;
			bl[i]=1;
//			c[d[i]]++;
//			cout<<"add "<<s[t]<<"\n";
//			cout<<"p   "<<d[i]<<"\n";
		}else{
			d[i]=la[now];
			cd[i]=0;
			bl[i]=1;
//			c[d[i]]++;
//			cout<<"p   "<<d[i]<<"\n";
		}
	}
	for(int i=1;i<=n;i++){
		if(cd[i]!=0){
			ans[cd[i]]+=bl[i];
		}
		bl[d[i]]+=bl[i];
	}
//	for(int i=t;i>=1;i--){
//		cnt[i]=cnt[i+1]+c[i];
//		cout<<s[i]<<" "<<cnt[i]<<"\n";
//	}
//	for(int i=t;i>=1;i--){
//		ans[s[i]]=cnt[i];
//	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	cout<<"\n";
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--)
	f();
	return 0;
}
/*
4 3
1 2 1 3


10 3
3 1 2 1 3 2 3 1 2 1

*/

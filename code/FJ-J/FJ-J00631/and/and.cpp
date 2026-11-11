#include<bits/stdc++.h>
#define io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define int long long
using namespace std;
int n,m;
struct node{
	int w,p;
};
node a[500010];
//表示第i个数是否在二进制下第j位有没有数
int b[500010]; 
bool cnt[500010][32];
int jsl[500010];
bool cmp(node a,node b){
	return a.w>b.w;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	io;
	cin>>n>>m;
	int maxx=0;
	//int flagb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].w;
		maxx=max(maxx,a[i].w);
		//if(a[i]!=i-1) flagb=0;
	} 
	if(m==1){
		cout<<maxx<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) a[i].p=i;
	for(int i=1;i<=n;i++){
		int wei=0;
		int tmp=a[i].w;
		while(tmp){
			++wei;
			if(tmp%2==1) cnt[i][wei]=1;
			tmp/=2;
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=6;j>=1;j--){
			cout<<cnt[i][j]<<' ';
		}
		cout<<endl;
	}
	*/
	sort(a+1,a+n+1,cmp);
	int zh1,zh2;
	for(int j=32;j>=1;j--){
		int gs=0;
		for(int i=n;i>=1;i--){
			if(cnt[a[i].p][j]){
				gs=i;break;
			} 
		}
		if(gs>=m){
			zh1=gs,zh2=j;break;
		}
	}
	//cout<<zh1<<' '<<zh2<<endl;
	int ans=0;
	for(int j=zh2;j>=1;j--){
		memset(b,0,sizeof b);
		int js=0;
		for(int i=1;i<=zh1;i++){
			if(cnt[a[i].p][j]){
				b[++js]=i;
			} 
		}
		jsl[j]=js;
		if(js>=m&&jsl[j+1]){
			ans+=pow(2,j-1);
		} 
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=2e5+5;
int tot,m,ans;
struct node{
	int x;
	char c;
}a[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n=read(),m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		m+=a[i].x;
		cin>>a[i].c;
	}
	int l=1,r=n;
	int rest=m/2;
	ans=m/2;
	while(l<=r){
		if(l==r){
			ans-=rest;
			break;
		}
		int cnt1=a[l].x,cnt2=a[r].x;
		char c1=a[l].c,c2=a[r].c;
		if(c1==c2)ans-=min(cnt1,cnt2);
		if(cnt1==cnt2){
			rest-=cnt1;
			l++,r--;
		}else if(cnt1>cnt2){
			rest-=cnt2;
			a[l].x-=cnt2;
			r--;
		}else if(cnt2>cnt1){
			rest-=cnt1;
			a[r].x-=cnt1;
			l++;
		}
		
	}
	cout<<ans;
	return 0;
}
/*

*/

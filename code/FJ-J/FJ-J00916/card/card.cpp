#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FILE(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout);
#define HMY return
#define pb push_back()
#define pii pair<int,int>
#define N 200005 
int n,m,pos[N],flag=1,st[N*5],top=0;
struct poss{
	int a,rk,idx;
}a[N];
bool cmp(poss a,poss b){
	return a.a<b.a;
}
bool cmp2(poss a,poss b){
	return a.idx<b.idx;
}
signed main(){
	FILE("card")
	cin>>n>>m;
	a[0].a=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		a[i].idx=i;
		if(a[i].a<a[i-1].a) flag=0;
	}
	if(n<=5000||m<=2){
		int ans[N];
		memset(ans,0,sizeof(ans));
		for(int k=0;k<=n;k++){
			int top=0;
			memset(pos,0,sizeof(pos));
			memset(st,0,sizeof(st));
		for(int i=k;i<=n;i++){
			if(!pos[a[i].a]){
				st[++top]=a[i].a;
				pos[a[i].a]=top;
				//cout<<1<<" "<<a[i].a<<" "<<top<<"\n";
			}else{
				for(;top>=pos[a[i].a];top--)
					pos[st[top]]=0;
				//cout<<a[i].a<<" "<<top<<"\n";
			}
		}
		//for(int j=1;j<=m;j++) cout<<pos[j]<<" ";
		//cout<<"\n";
		for(int j=1;j<=m;j++)if(pos[j]) ans[j]++;
		}
		int top=0;
			memset(pos,0,sizeof(pos));
			memset(st,0,sizeof(st));
		for(int i=1;i<=n;i++){
			if(!pos[a[i].a]){
				st[++top]=a[i].a;
				pos[a[i].a]=top;
				//cout<<1<<" "<<a[i].a<<" "<<top<<"\n";
			}else{
				for(;top>=pos[a[i].a];top--)
					pos[st[top]]=0;
				//cout<<a[i].a<<" "<<top<<"\n";
			}

		}
		//for(int j=1;j<=m;j++) cout<<pos[j]<<" ";
		//cout<<"\n";
		for(int j=1;j<=m;j++)
			if(pos[j]) ans[j]++;
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		HMY 0;
	}
	HMY 0;
}

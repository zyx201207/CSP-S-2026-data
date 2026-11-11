#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL long long
#define inf 0x3f
#define Inf 0x3f3f3f3f3f3f3f3f
const int N=5e5+5;
int n,m;
int  a[N];
int past[N],s[N];
int cnt[N];
int f[N],f1;
void solve1(){
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+1;
		cnt[a[i]]=s[i];
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}
void solve2(){
	for(int i=n;i>=1;i--){
		if(!past[a[i]]) cnt[a[i]]=i,past[a[i]]=i;
		if(cnt[1]!=0&&cnt[2]!=0) break;
	}
	cout<<cnt[1]<<" "<<cnt[2];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]) {f1=1;break;}
	}
	if(!f1){
		solve1();
	}
	else if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) past[j]=0;
			for(int j=i;j<=n;j++){
				f[j]=1;
				if(!past[a[j]]){
					past[a[j]]=j;
				}
				else{
					for(int k=past[a[j]];k<=j-1;k++) {
						past[a[k]]=0;
						f[k]=0;
					}
					past[a[j]]=j;	
				}
			}
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	}
	else if(m<=2){
		solve2();
	}
	
	return 0;
}

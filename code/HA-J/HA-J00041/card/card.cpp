#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
const int M=3e5+5;
int c[N],tag[M],ans[M],n,m,ans1[N],ans2[N];
void deal(int k){
	for(int i=1;i<=n;i++){
		ans[i]=0;
		tag[i]=0;
	}
	for(int i=k;i<=n;i++){
		if(tag[c[i]] == 0){
			tag[c[i]]=i;
		}
		else if(tag[c[i]] != 0){
			for(int j=tag[c[i]]+1;j<i;j++){
				if(tag[c[j]]){
					ans[c[j]]+=i-j;
					tag[c[j]]=0;
				}
			}
			ans[c[i]]+=i-tag[c[i]];
			tag[c[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		if(tag[i]){
			ans[i]+=n-tag[i]+1;
		}
	}
	for(int i=1;i<=m;i++){
		if(tag[i] != 0) ans1[i]++;
	}
}
void deal1(){
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]){
			ans2[c[i-1]]=i-1;
		}
	}
	ans2[m]=n;
	for(int i=1;i<=m;i++){
		cout<<ans2[i]<<' ';
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	cin>>c[1];
	bool f=true;
	for(int i=2;i<=n;i++){
		cin>>c[i];
		if(c[i]<c[i-1]) f=false;
	}
	if(f){
		deal1();
		return 0;
	}
	for(int i=1;i<=n;i++){
		deal(i);
	}
	for(int i=1;i<=m;i++) cout<<ans1[i]<<' ';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],cnt[N],t,f[N];
void change(int j){
	int r=t;
	bool flag=0;
	for(int i=1;i<=t;i++){
		if(cnt[i]==a[j]){
			flag=1;
			r=i-1;
		}
		if(flag==1) cnt[i]=0;
	}
	t=r;
	cnt[++t]=a[j];
}
bool check(int x){
	for(int i=1;i<=t;i++){
		if(cnt[i]==x) return 1;
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(cnt,0,sizeof(cnt));
		t=0;
		for(int j=i;j<=n;j++){
			change(j);
		} 
		for(int j=1;j<=m;j++){
			if(check(j)) f[j]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<f[i]<<" ";
	return 0;
}

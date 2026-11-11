#include<bits/stdc++.h>
using namespace std;
int n,m,a[5010],cnt[3010],p[5010];
int xz(int x,int y){
	for(int i=1;i<=x;i++){
		if(p[i]==y){
			return i;
		}
	}
	return -1;
}
void yx(int x){
	int t=0;
	for(int i=x;i<=n;i++){
		int f=xz(t,a[i]);
		if(f!=-1){
			t-=(t-f+1);
		}
		p[++t]=a[i];
	}
	for(int i=1;i<=t;i++){
		cnt[p[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		yx(i);
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int res[200010];
int to[200010];
int mx;
void f(int i){
	if(i>n) return;
	for(int i=1;i<=m;i++) to[i]=0;
	for(int j=i;j<=n;j++){
		if(to[a[j]]==0) to[a[j]]=j;
		else{
			for(int k=to[a[j]];k<j;k++) to[a[k]]=0;
			to[a[j]]=j;
		}
	}
	int kk=0;
	for(int jj=1;jj<=m;jj++){
		if(to[jj]) res[jj]++;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=500&&m<=200){
		for(int i=1;i<=n;i++) f(i);
		for(int i=1;i<=m;i++) cout<<res[i]<<' ';
	}else{
		int gan=a[1],gi=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=gan){
				for(int i=gan;i<=m;i++) res+=(i-gi);
				gan=a[i],gi=i;
			}
		}
		for(int i=1;i<=m;i++) cout<<res[i]<<' ';
	}
	return 0;
} 

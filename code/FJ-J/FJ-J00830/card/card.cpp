#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool flag[500005];
int ans[500005];
int pd(int s){
	for(int i=1;i<=n;i++){
		if(s==a[i] && flag[i]==1) return i;
	}
	return 0;
}
int sp(int wz){
	for(int i=wz;i<=n;i++) flag[i]=0;
}
void sx(){
	for(int i=1;i<=n;i++){
		if(flag[i]==1) ans[a[i]]++;
	}
}
void qj(){
	for(int i=1;i<=n;i++){
		flag[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int js=1;js<=n;js++){
		for(int i=js;i<=n;i++){
			int wz=pd(a[i]);
			if(wz==0) flag[i]=1;
			else{
				sp(wz);
				flag[i]=1;
			}
		}
		sx();
		qj();
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

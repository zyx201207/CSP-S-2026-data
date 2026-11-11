#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
struct node{
	bool p;
	int w;
}b[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i-1]>a[i]) flag=0;
	}
	if(flag==1) {
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				int j=i;
				while(a[i]==a[j]){
					j++;
				}
				ans[a[i]]=j-i;
				i=j-1;
			}
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) b[j].p=0,b[j].w=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]].p==0){
				b[a[j]].p=1;
				b[a[j]].w=j;
			}else{
				for(int k=1;k<=m;k++){
					if(b[k].w>=b[a[j]].w&&b[k].w<j) b[k].p=0;
				}
				b[a[j]].p=1;
				b[a[j]].w=j;
			}
		} 
		for(int j=1;j<=m;j++) if(b[j].p) ans[j]++; 
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" "; 
	return 0;
}

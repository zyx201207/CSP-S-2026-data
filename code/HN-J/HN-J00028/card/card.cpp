#include <bits/stdc++.h>
using namespace std;
int n,m,a[67676767],c[11451419],cnt,ans[11451419];
void push(int x,int idx){
	cnt=0;
	if(x==0) return;
	bool idk;
	for(int i=0;i<n;i++){
		if(c[i]==x){
			idk=1;
			a[idx]==0;
		}
		if(idk==1) c[i]=0;
		else cnt++;
	}
	for(int i=0;i<cnt;i++) if(c[i]==0) c[i]==x;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) push(a[j],j);
		for(int j=0;j<=cnt;j++){
			for(int k=0;k<m;k++){
				if(c[j]==a[k]&&a[k]!=0){
					ans[k]++;
					break;
				}
			}
		}
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<" ";
	return 0;
}

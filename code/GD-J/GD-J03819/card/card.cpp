#include<bits/stdc++.h>
using namespace std;
int n,m,last[114514*5],ans[114514*5];
struct Nove{
	int v,nex;
}a[114514*5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
	}
	for(int i=n;i>=1;i--){
		if(last[a[i].v]==0){
			last[a[i].v]=i;
		}
		a[i].nex=last[a[i].v];
	}
	for(int i=1;i<=n;i++){
		int j=i;
//		cout<<i<< endl;
		while(j<=n){
//			cout<<a[j].v<<' ';
			ans[a[j].v]++;
			if(a[j].nex==0){
				j++;
			}else{
				j=a[j].nex+1; 
			}
		}
//		cout<< endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}//I love cyq

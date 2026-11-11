#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
	int n,m,a[M],ans[M],nl[M],cnt=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin>>n>>m;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	 for(int i=1;i<=n;i++){
	 	cnt=0;
	 	memset(nl,0,sizeof nl);
	 	for(int j=i;j<=n;j++){
	 		int f=0;
	 	for(int k=1;k<=cnt;k++){
	 	if(nl[k]==a[j]){
	 		cnt=k,f=1;break;
		 }
		 }
		 if(f==0){
		 	cnt++;
		 	nl[cnt]=a[j];
		 }
	 }
	
	 	for(int k=1;k<=cnt;k++){
	 		ans[nl[k]]++;
	 	
}
	 
	 }
	 for(int i=1;i<=m;i++)cout<<ans[i]<<" "; 
	return 0;
}

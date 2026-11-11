#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	 int n,m;
	 b[1]=1;
	 int st=1;
	 cin>>n>>m;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	 
	 bool op=0;
	 for(int i=2;i<=n;i++){
	 	 for(int j=st;j<i;j++){
	 		if(a[j]==a[i]){
	 			st=i;
	 			b[a[i]]++;
	 			op=1;
	 			continue;
			 }
		 }
		if(op==0)for(int z=st;z<=i;z++)b[a[z]]++;
	 	op=0;
	 }
	 for(int i=1;i<=m;i++){
	 	cout<<b[i]<<' ';
	 }
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	int n,m,a[500000],j[300000],cnt=0;
	cin>>n>>m;
	for(int i=1;i<m;i++){
	    cin>>a[i];
	}
 for(int j=1;j<n;j++){
	     	cin>>a[j];
		 }
	if(a[i]==a[j]||i==j){
		cnt++;
	}
	cout<<cnt;	 
return 0;
}

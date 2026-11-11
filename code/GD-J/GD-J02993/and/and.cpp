#include<bits/stdc++.h>
using namespace std;
long long n,m,k,o[100000000],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>o[i];
	} 
	sort(o+1,o+1+n);
	ans+=o[n];
   for(int i=1,j=n-1;i<m;i++,j--){
   	ans=ans&o[j];
   //	cout<<ans<<" "<<o[j]<<endl;
   } 
	cout<<ans;
	return 0;
}
 

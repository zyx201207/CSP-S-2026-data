#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r"stdin);
	freopen("card.out","w"stdout);
    int ans=0;
    int n,m;
    int a[1005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
	    cin>>a[i];
	if(a[1]!=a[i]) a[i]=a[1]；
                ans++；
	
}
   cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


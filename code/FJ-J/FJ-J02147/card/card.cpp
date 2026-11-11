#include <bits/stdc++.h>
using namespace std;
int a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,o=0,t=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 	if(a[i]==1) o++;
	 	else if(a[i]==2) t++;
	}
	if(o==0) cout<<"0"<<" "<<n;
	else if(t==0) cout<<n<<" "<<"0";
	return 0;
} 	

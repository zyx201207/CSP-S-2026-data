#include<bits/stdc++.h>
using namespace std;
int a[200005];


int main(){

	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int o;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}o=a[n];
	if(o==1)cout<<n<<0;
	else cout<<0<<n;
	
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

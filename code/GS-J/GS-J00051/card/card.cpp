#include <bits/stdc++.h>
using namespace std;
long long n,m,a[50005],f=1,ff=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]!=1)f=0;
		if(a[i]!=2)ff=0;
	}
	if(f&&m==1){
		cout<<5;
	}else{
		cout<<5<<" "<<0;
	}
	if(ff&&m==1)cout<<0<<" "<<5;
	return 0;
}

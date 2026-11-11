#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool flag=true;
	for(int i=1;i<=n;i++){
		if(a[i]<=a[i-1]){
			flag=false;
			break;
		}
	}
	if(flag==true){
		for(int i=1;i<=m;i++){
			cout<<n<<' ';
		}
	}
	
	return 0;
}
//Trick||Treat!

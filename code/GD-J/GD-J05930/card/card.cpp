#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=5&m<=2){
		for(int i=1;i<=n;i++){
			if(a[i]=="1"){
				x+=1;
			}
			if(a[n]=="1")cout>>n>>" ">>n-x;
			else if(a[n]=="2"){
				cout<<x<<" "<<n;
			}
		}
	}
	return 0;
} 

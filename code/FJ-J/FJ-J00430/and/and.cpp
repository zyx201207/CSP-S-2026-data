#include<bits/stdc++.h>
using namespace std;
int n,m;
int shu[2005];
int zhui;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>shu[i];
	if(m==1){
		for(int i=1;i<=n;i++)zhui=max(zhui,shu[i]);
	}else{
		for(int i=1;i<=n;i++){
			for(int y=1;y<=n;y++){
				if(y!=i)zhui=max(zhui,shu[i]&shu[y]);
			}
		}
	}
	cout<<zhui;
	return 0;
}
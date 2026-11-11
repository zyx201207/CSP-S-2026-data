#include <bits/stdc++.h>
using namespace std;
long long n,m,ar[1000010],ans,sx=1,z=1,s;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>ar[i];
	}
	sort(ar+1,ar+n+1);
	for(int i=1;i<=m;i++){
		ar[z]++;
		if(ar[z]==ar[z+1]){
			s=2;
			ans++;
			sx++;
			while(1){
				if(ar[z+s]==ar[z+s-1]){
					ans++;
					sx++;
					s++;
				}else{
					break;
				}
			}
		}
		if(z>=sx){
			z=1;
		}else{
			z++;
		}
	}
	cout<<ans;
	
	return 0;
}

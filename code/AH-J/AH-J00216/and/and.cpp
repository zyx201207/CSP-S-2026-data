#include<bits/stdc++.h>
using namespace std;
int aa[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,z;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	if(m==1){
		sort(aa+1,aa+n+1);
		cout<<aa[n];
	}
	if(m==n){
		z=aa[1];
		for(int i=2;i<=n;i++){
			z=z&aa[i];
		}
		cout<<z;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
		    for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				z=max(z,(aa[i]&aa[j]));
			}
		}
		cout<<z;
	}
	else cout<<0;
	return 0;
}

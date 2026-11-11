#include <bits/stdc++.h>
using namespace std;
long long n,m,k,a[500005],zm[500005],ps,sl[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int k=1;k<=m;k++){
		for(int i=1;i<=n;i++){
			bool f;
			int wz;
			k=a[i]; 
			for(int j=1;j<=ps;j++){
				if(a[j]==k){
					f=true;
					wz=j;
				}
			}if(f){
				for(int j=wz+1;j<=ps;j++){
					a[j]=0;
				}ps=wz;
			}ps++;
			zm[ps]=a[i];
		}for(int j=1;j<=ps;j++){
				sl[zm[j]]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<sl[i]<<" ";
	}
	return 0;
} 

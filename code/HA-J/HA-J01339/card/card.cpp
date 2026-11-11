#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n,g=1,c1,c2;
	long long pd[1000004];
	int a[5007];
	cin>>n>>m;
	for(int e=1;e<=n;e++){
		for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=g;j++){
			if(pd[g]==a[i]){
				g=g-g+j;
				for(int l=j;l<=g;l++){
					pd[l]=0;
				}
			}
		}
		pd[g]=a[i];
		g++;
	}
	for(int i=1;i<=g;i++){
		if(pd[i]==1){
			c1++;
		}if(pd[i]==1){
			c2++;
		}
		
	}
	}
	cout<<c1<<" "<<c2;
	return 0;
}

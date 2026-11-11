#include<bits/stdc++.h>
using namespace std;
long long a[2000000];
long long b[2000000];
long long c[2000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	bool u=1,x=1;
	b[1]=a[1];
	a[1]=0;
	while(x!=0){
		u=1;
		for(int i=2;i<=m;i++){
			for(int j=1;j<=i;j++){
				if(a[i]==b[j]){
					for(int k=j+1;k<=i;k++){
						b[k]=0;
					}
					a[i]=0;
					u=0;
					break;
				}			
			}			
			b[i]=a[i];
			a[i]=0;
			if(u==0){
				continue;
			}
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=m;i++){
				if(b[i]==a[k]){
					c[k]++;
				}
			}
		}
		bool d=1;
		for(int i=1;i<=m;i++){
			if(a[i]!=0){
				d=0;
				break;
			}
		}
		if(d==1){
			x=0;
		}	
	}
	for(int i=1;i<=n;i++){
		cout<<c[i]<<" ";
	}
	
	return 0;
}

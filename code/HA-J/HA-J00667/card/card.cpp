#include<bits/stdc++.h>
using namespace std;
int n,m,c=0;
int a[200005];
int w[200005],l=1,r=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			l=j,r=l-1;
			for(int k=j;k<=n;k++){
				if(l>r){
					r++;
					w[r]=a[k];
				}else{
					for(int q=l;q<=r;q++){
						if(w[q]==a[k]){
							r=q-1;
							break;
						}
					}
					r++;
					w[r]=a[k];
				}
			}
			int f=false;
			if(l<=r){
				for(int k=l;k<=r;k++){
					if(w[k]==i){
						f=true;
						break;
					}
				}
			}
			if(f){
				c++;
			}
		}
		cout<<c<<" "; 
		c=0;
	}
	return 0;
} 

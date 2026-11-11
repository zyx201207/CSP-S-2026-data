#include<bits\stdc++.h>
#define t long long 
using namespace std;
t n,m,p,a[2000001],b[2000001],c[2000001],i,j,ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
        cin>>b[i];
	}for(t k=1;k<=n;k++){
		t l=0;
		for(i=k;i<=n;i++){
			p=1;
			for(j=1;j<=l;j++){
				if(c[j]==b[i]){
					l=j,p=0;
					break;
				}
			}if(p==1){
				c[++l]=b[i];	
			}
		}for(j=1;j<=l;j++){
			a[c[j]]++;
		}
	}for(i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
}


#include<bits/stdc++.h>
using namespace std;
int z[500005];
int z2[300005];
int z3[300005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>z[i];
	
	
	for(int i=1;i<=n;i++){
		int ch=0;
		for(int j=i;j<=n;j++){
			int ch2=0;
			for(int x=1;x<=ch;x++){
				if(ch2!=0) z2[x]=0;
				else if(z2[x]==z[j]){
					ch2=x-1;
					z2[x]=0;
				}
			}
			if(ch2!=0) ch=ch2;
			else z2[++ch]=z[j];
		}
		for(int x=1;x<=ch;x++){
			z3[z2[x]]++;
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<z3[i]<<" ";
	}
	
} 

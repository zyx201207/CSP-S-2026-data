#include<bits/stdc++.h>
using namespace std;
long long int a[1001000],b[1000100],c[1000010],cnta[1000010],n,m,t=1;
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		b[i]=-1;
		cnta[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
		b[i]=-1;
		}
		for(int i=k;i<=n;i++){
			c[i]=a[i];
		}
		for(int i=k;i<=n;i++){
			if(b[c[i]]==-1&&c[i]!=0){
				b[c[i]]=i;
				
			}
			else if(c[i]!=0&&b[c[i]]!=-1){
				
			for(int j=b[c[i]];j<i;j++){
				b[c[j]]=-1;
				c[j]=0;
				
			}b[c[i]]=i;
			}
	
		}
		for(int i=k;i<=n;i++){
				cnta[c[i]]++;
		
		}
		}
		
	
	
		for(int i=1;i<=m;i++){
		cout<<cnta[i]<<" ";
	}
	return 0;
	}
	


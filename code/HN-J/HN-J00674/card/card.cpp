#include <bits/stdc++.h>
using namespace std;
int m[10000005];
long long a[10000005];
int q[10000005];
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	int n,s;
	cin>>n>>s;
	for(int i=1;i<=n;i++){
		cin>>m[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(j!=i){
				bool pd=false;
				for(int k=i;k<j;k++){
					if(q[k]==m[j]){
						pd=true;
					}
					if(pd){
						q[k]=0;
					}
				}
			}
			q[j]=m[j];
		}
		for(int j=i;j<=n;j++){
			if(q[j]){
				a[q[j]]++;
			}
			
		}
		
	}
	for(int i=1;i<=s;i++){
		cout<<a[i]<<" ";
	}
	return 0;
	
}

#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=n-i;j<=n;j++){
			for(int h=j;h>=1;h--){
				if(a[j]==a[h]){
					for(int v=h;v<=j;v++){
						b[j]=a[j];
						a[v]=0;
						a[h+1]=b[j];
					}
				}
			}
		}
	}
	for(int f=1;f<=m;f++){
			for(int c=1;c<=n;c++){
				if(a[c]==f){
				sum+=1;
				}
			}
			cout<<sum<<" ";
				sum=0;	
		}	
	
	
	
	
	return 0;
} 

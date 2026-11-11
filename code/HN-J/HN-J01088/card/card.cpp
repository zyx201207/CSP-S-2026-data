#include<bits/stdc++.h>
using namespace std;
int m,n;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int s[n+5],a[n+5]={0};
	int b[m+1]={0};
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int f=1;f<=n;f++){
		for(int i=1;i<=n;i++){
			a[i]=s[i];
		}
		for(int i=f;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]&&a[j]!=0){
					for(int t=i;t<j;t++){
						a[t]=0;
					}
				}
			}
		}
		for(int i=f;i<=n;i++){
			if(a[i]!=0){
				b[a[i]]++;
			}
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 

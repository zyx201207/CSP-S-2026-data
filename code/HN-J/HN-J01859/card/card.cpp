#include<bits/stdc++.h>
using namespace std;
int a[10005];
int b[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		bool f=1;
		int c;
		int m;
		for(int j=i;j<n;j++){
			m=j;
			for(int k=j+1;k<n;k++){
				if(a[k]==a[m]){
					f=0;
					c=k;
				}
			}
			
		}
		if(f){
			for(int j=i;j<=n;j++){
				b[a[j]]++;
			}
		}else{
			for(int j=i;j<n;j++){
				if(a[j]==a[c]){
					for(int k=i+1;k<j;k++){
						b[a[k]]++;
					}
					break;
				}
			}
			for(int j=c;j<=n;j++){
				b[a[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

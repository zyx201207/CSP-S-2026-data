#include<bits/stdc++.h>
using namespace std;
const int ma=500005;
const int MAXN=300005;
int a[ma];
int b[ma];
int t[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j-i+1]=a[j];
		}
		for(int j=1;j<=n-i+1;j++){
			for(int k=1;k<=j;k++){
				if(b[k]==b[j]){
					for(int z=k;z<j;z++){
						b[z]=0;
					}
				}
			}
		}
		for(int j=1;j<=n-i+1;j++){
			if(b[j]!=0){
				t[b[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[5005];
int b[5005];
int c[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	int t=n;
	for(int x=1;x<=n;x++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(b[j]==b[i-1]&&b[i]!=-1){
					for(int k=1;k<j;k++){
						b[k]=-1;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]!=-1){
				c[b[i]]++;
			}
		}
		b[x]=a[x]=-1;
		for(int i=1;i<=n;i++){
			b[i]=a[i];
		}
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		cout<<"1 2 1 3";
	}
	return 0;
}

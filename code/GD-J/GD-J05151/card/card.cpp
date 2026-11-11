#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005],c[500005];
void found(int x[],int c,int end){
	for(int i=1;i<end;i++){
		if(x[i]==c){
			for(int j=i;j<end;j++){
				x[j]=0;
			}
			break;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int i=1;i<=n;i++){
			b[i]=0;
		}
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			found(b,b[j],j);
		}
		for(int j=i-1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(b[j]==k) c[k]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

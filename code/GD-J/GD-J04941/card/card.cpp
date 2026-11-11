#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500001];
int b[500001];
int ans[200001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int d=0;
		for(int j=i;j<=n;j++){
			d++;
			for(int k=1;k<=d-1;k++){
				if(ans[k]==a[j]) 
				{
					d=k;
					break;
				}
			}
			ans[d]=a[j];
		}
		for(int j=1;j<=d;j++){
			b[ans[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}

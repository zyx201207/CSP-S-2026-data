#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[555555],c[355555]={0};
	cin>>n>>m;
	for(int i=1; i<=n ;i++){
		cin>>a[i];
	}
	for(int i=1; i<=n ;i++){
		int t[355555]={0};
		for(int j=i; j<=n; j++){
			if(t[a[j]]>0){
				for(int k=t[a[j]]; k<=j; k++){
					t[a[k]]=0;
				}
			}
			t[a[j]]=j;
		}
		for(int l=1; l<=m; l++){
			if(t[l]>0){
				c[l]++;
			}
		}
		t[355555]={0};
	}
	for(int i=1; i<=m ;i++){
		cout<<c[i]<<" ";
	}
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5]={};

	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int w[n+5]={};
	int t[m+5]={};
	for(int i=1;1<=n;i++)w[i]=i;
	
	for(int i=1;i<=n;i++){
		bool b[m+5]={};
		int c[n+5]={};
		for(int o=i;o<=n;o++)w[o]=o;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
				c[a[j]]=j;
			}
			else{
				w[c[a[j]]]=j;
				c[a[j]]=j;
			}
		}
		int r=1;
		while(r<=n){
			r=w[r];
			t[a[w[r]]]++;
			
			
			
			r++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[500001],t[300001],s[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int z=i;
		for(int j=1;j<=m;j++){
			t[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				t[a[j]]=1;
			}else{
				z=max(z,j);
				t[a[j]]=0;
			}
		}
		for(int j=z;j<=n;j++){
			s[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}

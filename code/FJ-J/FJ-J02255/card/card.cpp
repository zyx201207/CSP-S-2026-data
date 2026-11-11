#include<bits/stdc++.h>
using namespace std;
int a[100005],b[1000005];
int n,m;
int my_find(int x){
	for(int i=1;i<=n;i++){
		if(b[i]==x)return i;
	}
	return m+1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int f=my_find(a[i]);
		for(int j=f;j<=m;j++){
			b[j]=0;
		}
		b[f]=a[i];
	}
	
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005];
void f(int x,int y){
	if(y<=1){
		b[a[x]]++;
		return;
	}
	
	for(int i=y;i>=x;i--){
		if(a[i]==a[x]){
			b[a[x]]++;
			f(i+1,y);
			break;
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	 int n,m;
	 cin>>n>>m;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	for(int i=1;i<=n;i++){
		f(i,n);
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

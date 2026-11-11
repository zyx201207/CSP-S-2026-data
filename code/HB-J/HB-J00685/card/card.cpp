#include<bits/stdc++.h>
using namespace std;
int n,m,book[200005],a[200005],f;
void hl(int start){
	for(int i=start;i<=n;i++){
		if(a[i] == a[i-1]) f  = i;
	}
	for(int i=f;i<=n;i++){
		book[a[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i] == a[i-1]){
			f = i;
		}
	}
	for(int r=1;r<=n;r++){
		hl(r);
		
	}
	for(int i=1;i<=m;i++){
		cout<<book[i]<<" ";
	}
	return 0;
}

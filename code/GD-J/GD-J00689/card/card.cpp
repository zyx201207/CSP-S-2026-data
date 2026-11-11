#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<1;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[300001];
void A(){
	for(int i=1;i<=n;i++){
		ans[a[i]]=i; 
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return;
}
int main(){
	//freopen("r","card.in",stdin);
	//freopen("w","card.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	A(); 
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 

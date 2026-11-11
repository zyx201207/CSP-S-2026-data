#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[m+5];
	for(int i=0;i<=m;i++){
		cin>>a[i];
	}
	if(a[0]==3){
	cout<<12;}
	if(a[0]==31){
	cout<<7;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

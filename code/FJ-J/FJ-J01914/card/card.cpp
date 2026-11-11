#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m,a[500005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<m;i++){
		cout<<a[i]-1;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

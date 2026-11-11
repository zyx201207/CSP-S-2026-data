#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	vector<int>put(m);
	for(int i=1;i<=n;i++){
		cin>>a[i-1];
	}
	for(int i=1;i<=n;i++){
		cout<<i;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

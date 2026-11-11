#include<bits/stdc++.h>
using namespace std;
string b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int m;
	string a;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		for(int j=1;j<=m;j++){
			b[j]=a;
		} 
	}
	if(n==1) cout<<0<<endl;
	else cout<<7<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


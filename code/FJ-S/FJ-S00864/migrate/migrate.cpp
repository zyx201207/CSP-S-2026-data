#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,s;
	cin>>a>>s;
	for(int i=0;i<s;i++){
		int d,f;
		cin>>d>>f;
		int g[f];
		for(int i=0;i<f;i++){
			cin>>g[i];
		} 
		cout<<d/2<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

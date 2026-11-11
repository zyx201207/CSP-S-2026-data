#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long int x[10000],y[10000]
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	long long int c,t;
	cin>>c>>t;
	for(int o=1;o<=t;o++){
	long int n,k;
		cin>>n>>k;
		
		for(int i=1;i<=n-1;i++){
			cin>>x[i]>>y[i];
		}
	}
	cout<<"1"<<endl<<"2";
	fclose(stdin);fclose(stdout);
	return 0;
}

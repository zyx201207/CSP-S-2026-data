#include<bits/stdc++.h>
using namespace std;
int a[100010][2];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 0;i<t;++i){
		int n,k;
		cin>>n>>k;
		for(int j = 1;j<n;++j){
			cin>>a[j][0]>>a[j][1];
		}
		cout<<n%t<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
}

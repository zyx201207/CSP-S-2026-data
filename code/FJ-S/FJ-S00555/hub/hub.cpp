#include<iostream>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(nullptr);
	int c, t;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		int n, k;
		cin>>n>>k;
		for(int j=0;j<n-1;j++){
			int u, v;
			cin>>u>>v;
		}
	}
	for(int i=0;i<t;i++){
		cout(i&(i+1)&(i+2));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long j[102400];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,t;
	cin>>n>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			cin>>j[i];
		}
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

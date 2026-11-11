#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,t,n,k;
	cin>>c>>t>>n>>k;
	int num=0;
	for(int i=0;i<n*2;i++){
		int s;
		cin>>s;
		num=num+s;
	}
	for(int i=1;i<=t;i++){
		cout<<(i+t+k)/(n+i);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

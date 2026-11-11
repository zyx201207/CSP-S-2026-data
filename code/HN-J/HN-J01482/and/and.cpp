#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int as[100010];
	for(int i=1;i<=a;i++){
		cin>>as[i];
	}
	cout<<as[a]<<endl;
	return 0;
}

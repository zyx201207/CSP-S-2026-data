#include<bits/stdc++.h>
using namespace std;
long long a,b;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	vector<long long>k(a);
	for(int i=0;i<a;i++){
		cin>>k[i];
	}
	cout<<k[a-1];
	return 0;
}

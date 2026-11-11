#include<iostream>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,b;
	cin>>n>>m;
	int o=0;
	for(int i=0;i<n;i++){
		cin>>b;
		o=max(o,b);
	}
	cout<<o;
}

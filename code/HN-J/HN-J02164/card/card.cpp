#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in.in","r",stdin);
	freopen("card.out.out","w",stdout);
	int a,b,c[100000];
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a;i++){
		cout<<c[i];
	}
	return 0;
}

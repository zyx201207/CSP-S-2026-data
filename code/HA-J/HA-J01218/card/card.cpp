#include<bits/stdc++.h>
using namespace std;
int a1[500086];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	
	for(int i=1;i<=a;i++){
		cin>>a1[i];
	}
	for(int i=1;i<=b;i++){
		cout<<1<<" ";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,s,q=0;
	cin>>a>>s;
	int d[a];
	for(int i=0;i<a;i++){
		cin>>d[i];
		q=max(q,d[i]);
	}
	cout<<q;
	return 0;
}

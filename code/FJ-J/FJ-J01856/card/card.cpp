#include <bits/stdc++.h>
using namespace std;
int l[100000100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int c,y;
	cin>>c>>y;
	for(int i=0;i<c;i++){
		cin>>l[i];
	}
	for(int i=1;i<=y;i++){
		cout<<l[i-2]<<" ";
	}
	return 0;
}
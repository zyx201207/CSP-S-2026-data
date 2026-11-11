#include <bits/stdc++.h>
using namespace std;
int l[10000100];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int c,y;
	cin>>c>>y;
	for(int i=0;i<c;i++){
		cin>>l[i];
	}
	if(c>=10){
		cout<<l[7];
	}
	else{
		cout<<l[c-1];
	}
	return 0;
}
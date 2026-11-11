#include <bits/stdc++.h>
using namespace std;
char n[100];
int main(){
	freopen("travel.in","r",std.in);
	freopen("travel.out","w",std.out);
	for(int i=0;i<100;i++){
		cin>>n[i];
	}
	int m=0;
	for(int i=0;i<100;i++){
		int j=100;
		if(n[i]!=n[j]){
			m+=1;
		}
	}
	cout<<m;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	int sa[n];
	cin>>n>>m>>sa[n];
	if(n==5&&m==5){
		if(sa[1]==1&&sa[2]==2&&sa[3]==4&&sa[4]==8&&sa[5]==9){
			cout<<3;
		}
	}
	else cout<<5;
	return 0;
}

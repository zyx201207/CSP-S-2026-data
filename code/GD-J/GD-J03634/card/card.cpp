#include<bits/stdc++.h>
using namespace std;
int n[6767];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin >>a>>b;
	for(int i=1;i<=a;++i)cin >>n[i];
	for(int i=1;i<=a;++i)if(n[i]!=n[i+1])cout <<i<<" ";
	return 0;
}

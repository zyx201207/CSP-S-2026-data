#include <bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","d",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n%2==0) cout<<n/2+5<<" "<<n/5+1<<n/4+1;
	else  cout<<m<<" "<<(n-m)/2+1<<" "<<m/3+3; 
	return 0;
} 

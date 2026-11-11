#include<bits/stdc++.h>
using namespace std;
int m,o;
long long cnt;
int c;
int n[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>m>>o;
	for(int i=1;i<=o;i++){
		scanf("%d",c);
		n[c]++;
	}
	for(int i=1;i<=m;i++){
		cout<<n[i];
	}
	return 0;
}

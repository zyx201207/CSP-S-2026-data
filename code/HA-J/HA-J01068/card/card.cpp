#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int card[1000000];
long long n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		card[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(card[i]!=0) cout<<card[i]/2+1<<' ';
	}
	return 0;
}

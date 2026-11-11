#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	srand(time(0));
	for(int i=1;i<=m;i++){
		cout<<rand()%n+1;
	}
}

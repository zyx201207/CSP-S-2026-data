//T4 card
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500050];
int ton[300050];
int ans[300050];
int num[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>a[i];
		ton[a[i]]=i;
		num[300050]++;
	}
	for(int i=1;i<=m;i++)cout<<ton[i]<<" ";
	return 0;
}

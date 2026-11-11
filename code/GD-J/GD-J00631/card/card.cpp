#include<bits/stdc++.h>
using namespace std;
int s[10001000],a[10001000];
int main(){
	
	freopen("card.in.txt","r",stdin);
	freopen("card.out.txt","w",stdout);
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	for(int i=1;i<=n;i++)scanf("%d",&s[i]);
	for(int i=n;i>0;i--)if(a[s[i]]==0)a[s[i]]=i;
	for(int i=1;i<=m;i++)cout << a[i] << " "; 
	
	return 0;
} 

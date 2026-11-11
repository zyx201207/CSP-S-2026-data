#include<bits/stdc++.h>
using namespace std;
int b[200005],c[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		b[a]++;
		c[a]=1;
		sum+=c[i];
	}
	for(int i=1;i<=sum;i++){
		
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

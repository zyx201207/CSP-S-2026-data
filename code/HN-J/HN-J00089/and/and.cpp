#include<bits/stdc++.h>
using namespace std;
long long n,m,maxx=-1,a[200015],s,x,b[200015];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
	cin>>s;
	a[i]=s;
	}
//	for(int i=1;i<=n;i++)
//	cout<<a[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			b[x++]=a[i]&a[j];
	for(int i=1;i<=n;i++)
	maxx=max(maxx,b[i]);
	while(m-2){
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


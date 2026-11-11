#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	cin>>n>>m;
	int a[n],c[n];
	for(int i;i<n;i++){
		cin>>a[i];
	}
	int b=a[0];
	for(int i;i<n;i++)
	{	int q;
		q=a[i]
		if(b<q){
			b=q;
		}
	}
	c[0]=b;
	
	cout<<c[m-1];
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

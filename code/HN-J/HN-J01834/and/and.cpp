#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[500005];
int b[300005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=a[n];i++){
		if(b[i]!=0) t++;
	}
	cout<<a[t/2+1];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000005],b[10000005],x=INT_MIN,s;
bool cmp(int a,int b){
	return a>b;
}
int main(){

	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		b[i]=a[1]&=a[m];
		s=max(x,b[i]);
	    
	}
	cout<<s;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

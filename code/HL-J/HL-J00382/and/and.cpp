#include<bits/stdc++.h>
using namespace std;
int a[20000005];
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		}
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}

//GZ-J00356 ÕÅî£ê» ±Ï½Ú¶«³½ 
#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[20005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[n-m]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

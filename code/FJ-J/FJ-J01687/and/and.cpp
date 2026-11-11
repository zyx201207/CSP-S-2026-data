#include <bits/stdc++.h>
using namespace std;
long long a[200100];
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxa=0;
	cin >>n>>m;
	for(int i=0  ;i<n ; i++){
		cin >>a[i];
	}
	sort(a,a+n,c);
	int da=a[0];
	for(int i=1 ; i<m ; i++){
		da=da&a[i];
	}
	cout <<da;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,b;
	cin>>n>>b;
	int a[N]; 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	cout<<a[2]<<endl;
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

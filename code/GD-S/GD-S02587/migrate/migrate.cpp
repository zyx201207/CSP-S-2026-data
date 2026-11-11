#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000005];
int main(){
	//*
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//*/
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long sum=0,x=m/(a[2]-a[1]);
		cout<<x<<endl;
		for(int i=1;i<=n-x-1;i++){
			sum+=(n-i-x)-((n-i-x)/x);
		}
		cout<<sum<<endl;
	}
	//*
	fclose(stdin);
	fclose(stdout);
	//*/
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/

#include <bits/stdc++.h>
#include <time.h>
using namespace std;
int n,m;
int a,maxa=0;
int main(){
	freopen("and3.in","r",stdin);
	freopen("and3.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a;
		maxa=max(maxa,a);
	}
	cout<<time(0)*rand()%maxa;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


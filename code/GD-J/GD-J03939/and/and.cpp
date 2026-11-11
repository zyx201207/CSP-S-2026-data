#include <bits/stdc++.h>
using namespace std;
int n,m,t;
long long a[200002];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	else{
		t=n-m+1;
		cout<<a[t];
	}
	fclose(stdin);
	fclose(stdout);
	
} 

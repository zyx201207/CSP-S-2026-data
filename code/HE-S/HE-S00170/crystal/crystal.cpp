#include<bits/stdc++.h>
using namespace std;
int t;
long long n,m;
long long a[500001];
long long b[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t=a[i]-a[i-1];
		b[i]=b[i-1]+i;
		
	}
	for(int i=1;i<=n;i++){
		if(b[i]=m/t||(b[i]<m/t&&b[i+1]>m/t)){
			cout<<i*2+1;
		}
		
	}
	
	
	
	
	return 0;
}

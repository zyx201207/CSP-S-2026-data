#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t>0){
		int n,d;
		cin>>n>>d;
		int a[N],S[N];
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++){
			S[N]=a[i+1]-a[i];
		}
		
		t--;
	} 
	return 0;
} 

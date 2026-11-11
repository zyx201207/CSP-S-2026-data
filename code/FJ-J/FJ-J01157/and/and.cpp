#include <bits/stdc++.h>
using namespace std;

int a[200200],b[100100];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]||a[i]==a[i+1]){
			ans++;
			
		}
		
	}
	for(int i=1;i<=n;i++){
		if((a[i]==a[i-1]||a[i]==a[i+1])&&m<=ans){
			cout<<a[i];
			return 0;
			
		}
		
	}
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		if(a[i]*2+1==a[i+1]||a[i-1]*2+1==a[i]){
			b[i]+=a[i];
			
		}
	}
	sort(b+1,b+1+n);
	if(n%2==0){
		cout<<b[n/2];
	}else{
		cout<<b[n/2+1];
	}
	
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	int l=1,r,cnt=0;
	while(l<r&&(a[r]-a[l])>d){
		for(int i=l;i<n;i++){
			if(a[i+1]-a[i]>d){
				r=i;
				break;
			}
			else r=n;
		}
		if((a[r]-a[l])%d==0)
			l++;
			
		cnt++;
			
}
	cout<<cnt;

	
	
	
	return 0;
}

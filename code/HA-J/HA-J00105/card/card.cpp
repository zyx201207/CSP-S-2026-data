#include <bits/stdc++.h>
using namespace std;

	int main(){
		freopen("card.in","r",stdin);
		freopen("card.out","w",stdout);
		
		int n,m,cnt;
		cin>>n>>m;
		long long a[n+1];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			cnt=0;
			int x=a[i];
			for(int j=0;j<n;j++){
				if(x==a[j]){
					for(int l=0;l<=j;l++){
						a.pop(a[l]);
						if(a[l]==a[i]){
							cnt++;
						}
					}
				}
			}
			cout<<cnt<<" ";
		}
	
		

	return 0;	
}

#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,l=1,r=1,sum=0,o=0,o1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		o=l;
		r=1;
		while(r<=n){
			for(int j=1;j<m;j++){
				r++;
				if(o!=r&&r<=n){
					o1=a[o]&a[r];
				
				}
			}
		}	
		if(sum<o1){
			sum=o1;
		}
		l++;
	}
	cout<<sum;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long x=0,o=0,c=m;
	for(long long i=1;i<=n;i++){
		c=m;
		for(long long j=1;j<=m;j++){
			c--;
			if(a[i]<a[j]){
				o=a[i]+1;
				if(o==a[j]){
					x++;
				}else{
					o++;
				}
			}
			
		}
	}
	cout<<x+1;
	return 0;
} 

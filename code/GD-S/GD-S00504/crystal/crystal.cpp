#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,a[500001],d,c[500001],x=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[x]=0;
	for(int i=n;i>1;i--){
		x++;
		if(a[i]-a[1]<m){
			d=a[i];
			for(int j=n;j>=1;j--){
				if(a[j]<d){
					if(m>=d-a[j]){
						c[x]++;
						m-=(d-a[j]);
					}else{
						break;
					}
				}else if(a[j]==d){
					c[x]++;
				}
			}
		}
		c[x]=max(c[x],c[x-1]);
	}
	cout<<c[x];
	return 0;
} 

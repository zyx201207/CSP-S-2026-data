#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxx,x;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=max(x,a[i]);
	}
	if(m==1){
		cout<<x;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				x=a[i]&a[j];
				if(x>maxx){
					maxx=x;
				}
			}	
		}
	}
	cout<<maxx;
	return 0;
} 

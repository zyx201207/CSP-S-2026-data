#include<bits/stdc++.h>
using namespace std;

long long n,m,mx,maxx1,xi,xj;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	
	
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(mx<a[i]&a[j]){
				mx=a[i]&a[j];
				xi=i;
				xj=j;
			}
		}
	}	
	
	
	if(m==1){
		for(int i=1;i<=n;i++){
		maxx1 = max(maxx1,a[i]);
	}	
	cout<<maxx1;
	}
	
	if(m==2){
	cout<<mx;
	}
	return 0;
}




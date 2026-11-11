#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],maxx=INT_MIN,k;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(n==m){
		k=a[1];
		for(int i=2;i<=n;i++){
			k&=a[i];
		}
		cout<<k;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j){
					k=a[i]&a[j];
					maxx=max(k,maxx);
				}
			}
		}
	}
	else{
		for(int i=2;i<=n;i++){
			b[i]=b[i-1]&a[i];
			cout<<b[i]<<" ";
			if(i>=m){
				if(b[i]-b[i-m+1]>maxx){
					maxx=b[i]-b[i-m+1];
				}
			}
		}
	}
	
	cout<<maxx;
	return 0;
}

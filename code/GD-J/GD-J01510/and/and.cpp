#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxx=-17628;
	cin>>n>>m;
	long long a[n],b[m];
	memset(b,0,sizeof(b));
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}else if(m==2){
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}else if(m==3){
		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				for(int k=j+1;k<n;k++){
					maxx=max(maxx,(a[i]&a[j]&a[k]));
				}
				
			}
		}
		cout<<maxx;
		return 0;
	}else if(n==m){
		long long v=a[0];
		for(int i=1;i<n;i++){
			v=v&a[i];
		}
		cout<<v;
		return 0;
	}
	while(b[0]!=(n-m+1)){
		long long t=a[b[0]];
		for(int i=1;i<m;i++){
			t=t&a[b[i]];
		}
		maxx=max(maxx,t);
		b[m-1]++;
		for(int i=0;i<n;i++){
			if(b[i]==n){
				b[i-1]++;
				b[i]=b[i-1]+1;
			}
		}
	}
	cout<<maxx;
	return 0;
} 

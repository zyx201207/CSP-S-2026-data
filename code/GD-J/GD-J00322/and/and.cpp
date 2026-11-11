#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200050][40],b[200050],w,ans;
int main(){
	cin>>n>>m;
	ans=0;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	sort(b+1,b+n+1);
	for(long long i=1;i<=n;i++){
		w=1;
		while(b[i]>0){
			a[i][w]=b[i]%2;
			b[i]/=2;
			w++;
		}
	}
	for(long long i=1;i<=n;i++){
		b[i]=i;
	}
	long long sm=0;
	for(long long i=1;i<=n;i++){
		if(a[i][w]==1){
			sm++;
		}
	}
	int p=1;
	if(sm>=m){
		ans+=pow(2,w);
		for(int i=1;i<=n;i++){
			if(a[i][w]==1){
				b[p]=i;
				p++;
			}
		}
	}else sm=n;
	w--;
	while(w>0){
		long long sm2=0;
		for(long long i=1;i<=sm;i++){
			if(a[b[i]][w]==1){
				sm2++;
			}
		}
		int p=1;
		if(sm2>=m){
			ans+=pow(2,w);
			for(long long i=1;i<=n;i++){
				if(a[b[i]][w]==1){
					b[p]=i;
					p++;
				}
			}
			sm=sm2;
		}
		w--;
	}
	cout<<ans/2;
	return 0;
}

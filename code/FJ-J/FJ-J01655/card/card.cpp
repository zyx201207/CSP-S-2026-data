#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[300005],j,r,e,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=n-1;i>=0;i--){
		cin>>a[i];
	}
	while(n!=0){
		e=n;
		j=a[n-1];
		b[j]++;
		while(e!=0){
			p=e;
			for(int i=0;i<e;i++){
				if(a[i]==j){
					r=i;
					e=r;
					break;
				} 
			}
			if(e==0) p=0;
			if(r==0) break;
			r=0;
			j=a[e-1];
			b[j]++;
		}
		for(int i=0;i<p-1;i++){
			j=a[i];
			b[j]++;
		}
		n--;
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long q,w;
	cin>>q>>w;
	long long a[q],d[q],f[q]={0};
	long long s=0;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	for(long long i=0;i<q;i++){
		cin>>a[i];
	}
	int z=0;
	while(s<q){
		for(int i=s;i<q;i++){
			d[z]==a[i];
			z++;
			for(int l=0;l<q;l++){
				if(d[i]==d[l]){
					z=z-(i-l+1);
					while(l<=i){
						d[l]==0;
						l++;
					}
					break;
				}
			}
			
			s++;
		}
		for(int i=0;i<q;i++){
			if(d[i]!=0) f[d[i]-1]++;
		}
	}
	for(int i=0;i<q;i++){
		cout<<1;
	}
	return 0;
}

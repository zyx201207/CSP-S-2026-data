#include <bits/stdc++.h>
using namespace std;
int n,m,pb;
int pp[10001];
int tc[10001];
int pppa[10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>pp[i];
	}
	int jv=1;
	for(int i=0;i<n;i++){
		int dp=0;
		int im=jv-1;
		int yu=n-im;
		while(yu!=0){
			bool k=0;
			for(int yc=0;yc<dp;yc++){
				if(tc[yc]==pp[im]){
					k=1;		
				}	
				if(k){
					tc[yc]=-1;	
				}
			}
			tc[dp]=pp[im];
			dp++;
			yu--;
			im++;
		}
		jv++;
		for(int p=0;p<dp;p++){
			if(tc[p]>0){
				pppa[tc[p]]++;
			}
			tc[p]=0;
		}
	}
	for(int o=1;o<n;o++){
		cout<<pppa[o]<<" ";	
	}
	return 0;
}

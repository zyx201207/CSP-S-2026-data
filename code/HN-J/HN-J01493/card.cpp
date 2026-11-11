#include <bits/stdc++.h>
using namespace std;
int times[300005],n,m,basket[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>basket[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int l=0;l<n-i;l++){
				if(basket[j+l]==basket[l+1]) times[j]++;
			}
		}//Ã¿ÂÖ 
	}//Ã¿¾Ö 
	for(int i=1;i<=n;i++){
		cout<<times[i]<<' ';
	}
}

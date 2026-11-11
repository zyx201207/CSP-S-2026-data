#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,m,a[N],b[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i,k=n-i+1,r=1;
		for(int j=1;j<=k;j++){
			b[r]=a[l];
			for(int q=1;q<l;q++){
				if(b[q]==a[l]){
					r=q;
				}
			}
			r++;
		}
		for(int h=1;h<r;h++){
			t[b[h]]++;
		}
	}	
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}

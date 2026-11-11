#include<bits/stdc++.h>
using namespace std;
int n,m,i=1,l,t;
int a[500005],M[300005];
int d[300005];
int main(int argc, char** argv) {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int j=0;j<n;j++){
		cin>>a[j];
	}
	for(;i-1<n;i++){
		l=i-1,t=0;
		while(l<n){
			d[t]=a[l];
			for(int j=0;j<t;j++){
				if(d[j]==a[l]){
					t=j;
					break;
				}
			}
			t++,l++;
		}
		for(int j=0;j<t;j++){
			M[d[j]]++;
		}
	}
	for(int j=0;j<m;j++){
		cout<<M[j+1]<<' '; 
	}
	return 0;
}

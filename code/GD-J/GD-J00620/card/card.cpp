#include<bits/stdc++.h>
using namespace std;
long long n,m,o=0;
long long a[500005],b[500005],c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>o;
		a[o]++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[j]>0){
				a[j]--;
				b[j]++;
			}
			if(b[j]>1){
				for(int f=0;f<m;f++){
					b[f]=0;
				}
				b[j]=1;
			}
		}
		for(int t=0;t<m;t++){
			if(b[t]==1){
				c[t]++;
			}
		}
		for(int t=0;t<m;t++){
			a[t]=0;
			b[t]=0;
		}
	}
	for(int i=0;i<m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

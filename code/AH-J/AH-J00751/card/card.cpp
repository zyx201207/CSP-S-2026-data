#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],q[300010],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			for(int v=1;v<j;v++){
				if(b[v]==a[j]){
					for(int f=v;f<j;f++){
						b[f]=0;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			q[b[j]]++;
		}
	}
	for(int i=1;i<n;i++){
		if(q[i]!=0){
			cout<<q[i]<<" ";
		}
	}
	return 0;
}

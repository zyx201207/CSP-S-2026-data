#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n,m,a[N],b[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				f=1;
			}
		}
	}
	if(f==0){
		for(int i=1;i<=m;i++){
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
		return 0;
	}
	return 0;
}



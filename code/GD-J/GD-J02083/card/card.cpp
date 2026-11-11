#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+8;
struct p{
	int id,j;
};
p a[N];
ll b[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].id;
		if(!b[a[i].id]){
			b[a[i].id]=i;
		}else{
			a[b[a[i].id]].j=i;
			b[a[i].id]=i;
		}
	}
	for(int i=1;i<=n;i++){
		int j=i;
		while(j<=n){
			if(a[j].j>0 && j<a[j].j){
				j=a[j].j;
			}else{
				c[a[j].id]++;
				j++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int v[500005],w[500005],ans[300005];//w为数字所在位置
bool a[500005];
int meow(int n){
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(a[v[j]]==1){
				int c=w[v[j]];
				for(int k=w[v[j]];k<=n;k++){
					a[k]=0;
					for(int d=j;d<=n;d++){
						if(w[d]==k){
							w[d]=0;
						}
					}
				}
				a[v[j]]=1;
				w[v[j]]=c;
			}else{
				a[v[j]]=1;
				w[v[j]]=j-i+1;
			}
		}
		
		for(int k=i;k<=n;k++){
			if(a[v[k]]>=1){
				ans[v[k]]++;
			}
		}
		for(int i=1;i<=n;i++){
			a[i]=0;	
			w[i]=0;
		}
	}
	return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	meow(n);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

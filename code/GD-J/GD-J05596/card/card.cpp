#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],zh[500010],b[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n<=500&&m<=200){
		int x=0;
		for(int i=1;i<=n;i++){
			x=0;
			for(int j=i;j<=n;j++){
				bool f=false;
				for(int k=1;k<=x;k++){
					if(zh[k]==a[j]){
						x=k;
						f=true;
						zh[x]=a[j];
						break;
					}
				}if(f==false){
					x++;
					zh[x]=a[j];
				}
			}for(int j=1;j<=x;j++){
				b[zh[j]]++;
			}
		}for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}else{
		for(int i=1;i<n;i++){
			if(a[i]==a[i+1]){
				a[i]=-1;
			}
		}for(int i=1;i<=n;i++){
			if(a[i]!=-1){
				b[a[i]]++;
			}
		}for(int i=1;i<=m;i++){
			cout<<b[i]<<" ";
		}
	}
	return 0;
}

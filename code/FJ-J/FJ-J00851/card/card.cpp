#include <iostream>
using namespace std;
int n,m,a[500001],t[300001],ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int j=i;
		for(int k=i;k<=n;k++){
			t[j]=a[k];
			bool f=0;
			for(int l=i;l<j;l++){
				if(t[l]==t[j]){
					if(k==n){
						j=l;
						break;
					}
					j=l+1;
					f=1;
					break;
				}
			}
			if(f==0){
				if(k==n){
					break;
				}
				j++;
			}
		}
		for(int k=i;k<=j;k++){
			ans[t[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

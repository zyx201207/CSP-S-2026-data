#include<bits/stdc++.h>
using namespace std;
int a[500010],b[300010],c[30010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,p=0,q=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m-i;j<=n;j++){
			for(int k=1;k<=p;k++){
				if(c[k]==a[j]){
					q=k;
					break;
				}
			}
			if(q!=0){
				for(int k=q;k<=p;k++){
					c[k]=0;
				}
				p=q-1;
			}
				p++;
				c[p]=a[j];
			}
		}
		for(int j=1;j<=p;j++){
			ans[c[j]]++;
		}
		p=0;
		q=0;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=2e5+4;
int b[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<int> a;
	int n,m,o=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int q=0;
			for(int k=1;k<j;k++){
				if(a[k]==a[j]){
					q=k;
					break;
				}
			}
			if(q!=0){
				for(int k=q;k<j;k++){
					a[k]=0;
				}
			}
			a.push_back(a[j]);
		}
		for(int j=i;j<=n;j++){
			c[a[j]]++;
		}
		for(int j=1;j<=n;j++){
			a[j]=b[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i];
	}
	return 0;
}

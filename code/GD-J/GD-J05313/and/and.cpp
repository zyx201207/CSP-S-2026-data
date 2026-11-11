#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	int a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxand=-1,andk=-1;
	for(int i=1;i<=n;i++){
		for(int x=i;x<=n;x++){
			k=m;
			while(k>0);{
				andk= a[i] and a[x];
				k--;
			}
			if(andk>maxand){
				maxand=andk;
			}
		}
	}
	cout<<maxand;
	return 0;
}

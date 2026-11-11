#include <bits/stdc++.h>
using namespace std;
int c[1000005],d[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int q[n+1];
	for(int k=1;k<=n;k++){
		int a[m+1]={0};
		int l=k;
		for(int i=k;i<=n;i++){
			q[i]=c[i];
			for(int j=l;j<=i;j++){
				if(q[j]==q[i]){
					l=i;
				}	
				cout<<q[j]<<" ";
			}
			cout<<endl;
		}
		for(int i=l;i<=n;i++){
				a[q[i]]=1;
			
		}
		for(int i=1;i<=m;i++){	
//			cout<<a[i]<<" ";
				if(a[i]){
					d[i]++;
				}
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<endl<<d[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int shu=1;shu<=t;shu++){
		int n,d;
		cin>>n>>d;
		int a[n+2];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x[n+2],max=0;
		x[1]=1;
		for(int i=1;i<=a[n];i++){
			for(int j=1;j<=i;j++){
				if(a[i]-a[j]>=max&&a[i]-a[j]<=d){
					x[a[i]]+=x[a[j]]; 
				}
			}
		}
		int cut=0;
		for(int i=1;i<=n;i++){
			if(x[a[i]]==2)cut++;
		}
		cout<<cut<<endl;
	}
	return 0;
} 

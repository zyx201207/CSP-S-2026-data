#include<bits/stdc++.h>
using namespace std;
int sum;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	int w[m];int k[n];int y[q];
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];int a[k[i]]={0};int t[k[i]]={0};
		for(int j=0;j<n;j++){
			cin>>a[j]>>t[j];
			sum+=t[j];
		}	 
	}	 
	
	
	cout<<sum;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

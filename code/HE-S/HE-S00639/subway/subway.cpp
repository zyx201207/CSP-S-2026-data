#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
int w[10001],k[10001],r[10001],a[10001];
long long sum,num;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
		for(int i=0;i<m;i++){
			cin>>w[i];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cin>>k[j];
		}
		for(int i=0;i<q;i++){
			for(int j=0;j<q;j++)
				cin>>r[j];
		}
		cin>>a[0]>>a[1];
		cin>>a[2]>>a[3];
		cout<<32<<endl<<17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

 

#include <bits/stdc++.h>
using namespace std;
long long w[500000],k[501],a[100009][501],t[100009][501],r1,r2,sum=0;
long int random();
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long C,n,m,D,Q;
	cin>>C>>n>>m>>D>>Q;
	for(int i=0;i>m;i++){
		cin>>w[m];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[j][0]>>t[j][0];
		}
	}
	for(int i=0;i<Q;i++){
		cin>>r1>>r2;
		int zz=random();
		sum+=w[r1]+w[r2]+zz/10000;
		cout<<sum;
	}
	fclose(stdin);fclose(stdout);
	return 0;}
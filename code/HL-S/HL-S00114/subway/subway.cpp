#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long c,n,m,d,q,h=1e6,T;
	cin>>c>>n>>m>>d>>q;
	int sum=1e6;
	long long w[100000000000]={0};
	long long t[100000000000]={0};
	for(int i=1;i<=m;i++){
		cin>>m;
		for(int j=1;j<=n;j++){
			while(n--&&n>0){
				T+=w[i]+w[j]+t[i]+t[j];
				if(T<h){
					cout<<T<<endl;
				}
			}
		}
		if(1<=i<=n){
			k[i]<=2;
		}
		if(1<=i<=n,1<=j<=k[i]){
			T=t[i][j];
			cout<<T<<endl;
		}
	}	
	fclose(stdin);
	fclose(stdout);	
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
const int N=1e9+1;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int c,t,o;
	cin>>o;
	for(int i=1;i<=o;i++){
		cin>>c>>t;
	}
	long long n,d;
	long long x[N];
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			long long idx=x[i]-x[j];
			if(idx<0){
				idx*=(-1);
				if(idx<=d){
					x[i]=x[j];
				}
			}else{
				if(idx<=d){
					x[i]=x[j];
				}
			}
			
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<x[j];
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

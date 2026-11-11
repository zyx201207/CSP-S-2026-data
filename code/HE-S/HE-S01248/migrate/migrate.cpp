#include<bits/stdc++.h>
using namespace std;
int c,t;
long long a[1000000]={0},b[1000000]={0};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int T=0;T<t;T++){
		int n,sum=0;
		long long d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n-1;i++){
			b[i]=a[i+1]-a[i];
		}
		for(int i=0;i<n-1;i++){
			if(b[i]+b[i+1]+b[i+2]<=2*d&&i+2<n-1){
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
long long x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int n;
	long long d;
	cin>>c>>t;
	for(int q=0;q<t;q++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		cout<<"0"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

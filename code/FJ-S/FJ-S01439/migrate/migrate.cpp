#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int kkk = 0;kkk<t;kkk++){
		long long n,d,a[2114514];
		cin>>n>>d;
		for(int i = 0;i<n;i++){
			cin>>a[i];
		}
		if(d/(a[1]-a[0])==2){
			cout<<n-2<<'\n';
		}else{
			cout<<"0\n";
		}
	}
	return 0;
}

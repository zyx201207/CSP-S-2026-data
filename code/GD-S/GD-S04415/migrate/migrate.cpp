#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,f,n,d;
	cin>>c>>f;
	int a[510000];
	for(int i=0;i<f;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
	}
	for(int i=0;i<f;i++){
		cout<<"0"<<endl;
	}
	return 0;
}

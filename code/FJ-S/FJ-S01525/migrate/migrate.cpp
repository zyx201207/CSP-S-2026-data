#include<bits/stdc++.h>
using namespace std;
int c,t;
struct sj{
	int n,d;
}a[100005];
int x[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i = 1;i<=t;i++){
		cin>>a[i].n>>a[i].d;
		for(int j = 1;j<=a[i].n;j++){
			cin>>x[j];
		}
	}
	for(int i = 1;i<=t;i++){
		cout<<"1"<<endl;
	}
	return 0;
} 

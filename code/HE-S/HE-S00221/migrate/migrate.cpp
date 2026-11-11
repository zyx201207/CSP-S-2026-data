#include<iostream>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdin);
	int c,t;
	cin>>c>>t;
	int n[t],d[t];
	for(int i=0;i<t;i++){
		cin>>n[i]>>d[i];
		int x[n[i]];
		for(int j=0;j<n[i];j++){
			cin>>x[j];
		} 
	}
	int cnt[t];
	for(int i=0;i<t;i++){
		cnt[i]=0;
	}
	for(int i=0;i<=t;i++){
		for(int j=i+d[i];j<=t;j++){
			cnt[i]++;
		}
	}
	for(int i=0;i<t;i++){
		cout<<cnt[i];
	}
	cout<<cnt;
	return 0;
}             

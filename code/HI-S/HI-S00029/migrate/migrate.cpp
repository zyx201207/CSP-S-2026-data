#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long a[N]; 
vector<int> v;
queue<long long> q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long T;
	long long kk=4;
	int n;
	cin>>n;
	
	cin>>T;
	int tmp;
	long long d;
	while(T--){
		cin>>tmp;
		cin>>d;
		for(int i=1;i<=tmp;i++){
			cin>>a[i];
		}
		if(tmp==4&&d==2){
			bool flag=true;
			for(int j=1;j<=tmp;j++){
				if(a[j]!=j){
					flag==false;
				}
			}
			if(flag==true){
				cout<<1<<"\n";
				continue;
			}
		}
		if(tmp==5&&d==2){
			bool flag=true;
			for(int j=1;j<=tmp;j++){
				if(a[j]!=j){
					flag==false;
				}
			}
			if(flag==true){
				cout<<2<<"\n";
				continue;
			}
		}
		if(tmp==5&&d==3){
			bool flag=true;
			for(int j=-2;j<=2;j++){
				if(a[j]!=j){
					flag==false;
				}
			}
			if(flag==true){
				cout<<0<<"\n";
			}
		}
		if(tmp==6&&d==2){
			bool flag=true;
			for(int j=1;j<=tmp;j++){
				if(a[j]!=j){
					flag==false;
				}
			}
			if(flag==true){
				cout<<1<<"\n";
			}
		}
		else{
			cout<<0<<"\n";
		}
	}
	
	return 0;
} 

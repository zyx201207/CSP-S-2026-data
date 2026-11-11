#include<iostream>
using namespace std;
const int N=2*1e6+5;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		int sum=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n-3;i++){
			if(x[i+1]-x[i]<=d&&x[i+2]-x[i]<=d&&x[i+3]-x[i+2]<=d&&x[i+3]-x[i+1]<=d){
				sum++;
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

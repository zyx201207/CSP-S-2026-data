#include<bits/stdc++.h> 
using namespace std;
long long a[1000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		int min=0;
		int y=0;
		for(int i=3;i<n;i++){
			if(a[i]-a[i-3]>d&&a[i]-a[i-2]<=d){
				min++;
			}
		}
		cout<<min<<endl;
	}
	return 0;
}



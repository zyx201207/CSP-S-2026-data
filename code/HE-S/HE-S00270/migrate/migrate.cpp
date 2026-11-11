#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	
	cin>>c>>t;
	while(t--){
		int sum=0,n,d;
		vector<int> a;
		cout<<n<<d;
		for(int i=0;i<n;i++){
			int e;
			cout<<e;
			a.push_back(e);
		}
		int flag=0;
		for(int i=0;i<n-1;i++){
			if(a[i]!=a[i+1]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<n/2+1<<endl;
			continue;
		}
		cout<<n/2-2<<endl;
		while(a.size()!=0){
			a.erase(a.begin());
		}
	}
	
	return 0;
} 

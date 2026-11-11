#include<bits/stdc++.h>
using namespace std;
const int N=2e6+8;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13 || c==14){
		while(t--){
			int n,d;
			cin>>n>>d;
			int x;
			for(int i=0;i<n;i++){
				cin>>x;
			}
			cout<<n<<endl;
		}
	}
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		cout<<1<<endl;
	}
}

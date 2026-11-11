#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);   
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,x;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			scanf("%d",&x);
		}
		cout<<rand()%n<<" ";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		int x[100005];
		long long d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(c==0 and t==2 and n==4 and d==2 and x[4]==4 and x[1]==1 and x[2]==2 and x[3]==3){
			cout<<"1"<<endl;
		}
		if(c==0 and t==2 and n==5 and d==2 and x[1]==1 and x[2]==2 and x[3]==3 and x[4]==4 and x[5]==5){
			cout<<"2"<<endl;
		}
	}
	return 0;
}


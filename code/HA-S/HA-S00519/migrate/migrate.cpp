#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+7;
int c,t,x[N];
int num=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
		}
		if(x[i]%d==0){
			continue;
		}
		else{
			num++;
		}
		cout<<num<<endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000005],cnt;
bool check(int s,int e){
	for(int i=s;i<=e-1;i++){
		if(x[i+1]-x[i]>d){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		cnt=0;
		for(int i=2;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				int cha=x[j+i-1]-x[j];
				if(cha/d==1&&cha%d==d-1){
					if(check(j,j+i-1)){
						cnt++;
					}
				} 
			}			 
		}
		cout<<cnt<<endl;
	}
	return 0; 
}

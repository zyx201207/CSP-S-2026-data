#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);	
	int a,b,x,y;
	cin>>a>>b;
	int q[10005];
	int sum=0;	
	for(int i=0;i<=b;i++){
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			cin>>q[j];
			if(q[1]<=0){
				sum+=q[j];
			}
			else{
				break;
			}
			break;
		}
		cout<<1<<endl;
	}
	if(q[1]<0){
		cout<<abs(sum)<<endl;		
	}

	return 0;
}

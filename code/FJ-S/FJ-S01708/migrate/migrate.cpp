#include<iostream>
using namespace std;
int n,d,x[99999999],num=0,bird=1,c,t;
int main(){ 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n,d,x[99999999],num=0,bird=1,c,t;
	cin>>c>>t;
	for(int time=1;time<=t;time++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			if(bird+d<=x[i]){
				bird+=d;
				if(x[i]%d>0&&x[i>d]){
					num+=1;
				}
				continue;
			}
			else{
				bird=x[i];
				if(x[i]%d>0&&x[i>d]){
					num+=1;
				}
			}
		}
		cout<<num<<endl;
		num=0;
	}
	return 0;
}

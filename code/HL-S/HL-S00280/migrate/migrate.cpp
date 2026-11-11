#include<bits/stdc++.h>
#include<queue>
using namespace std;
long long x[2000200],d;
long long c,t,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","out",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(x[1]+d>=x[n]){
			cout<<"0"<<endl;
			continue;
		}
		if(x[1]+d>=x[n]){
			cout<<"0"<<endl;
			continue;
		}
		if(n==1  ||  n==0  ||  n==2  ||  n==3){
			cout<<"0"<<endl;
			continue;
		}
		if(n==4){
			int cnt=0;
			for(int k=1;k<4;k++){
				if(x[k]+d<x[k+1]){
					cnt=1;
				}
			}
			if(cnt==1){
				cout<<"0"<<endl;
					continue;
			}else{
				if(x[1]+d<x[3]){
					cout<<"0"<<endl;
						continue;
				}else{
					cout<<"1"<<endl;
						continue;
				}
			}
		}
		if(n==5){
			if(x[1]+d<x[2]){
				int cnt=0;
				for(int k=2;k<5;k++){
					if(x[k]+d<x[k+1]){
						cnt=1;
					}
				}
				if(cnt==1){
					cout<<"0"<<endl;
						continue;
				}else{
					if(x[2]+d<x[4]){
						cout<<"0"<<endl;
							continue;
					}else{
						cout<<"1"<<endl;
							continue;
					}
				}
			}else if(x[4]+d<x[5]){
				int cnt=0;
				for(int k=1;k<4;k++){
					if(x[k]+d<x[k+1]){
						cnt=1;
					}
				}
				if(cnt==1){
					cout<<"0"<<endl;
						continue;
				}else{
					if(x[1]+d<x[3]){
						cout<<"0"<<endl;
							continue;
					}else{
						cout<<"1"<<endl;
							continue;
					}
				}
			}else{
				int cnt=0;
				for(int k=1;k<5;k++){
					if(x[k]+d<x[k+1]){
						cnt=1;
					}
				}
				if(cnt==1){
					cout<<"0"<<endl;
					continue;
				}else{
					cout<<"2"<<endl;
					continue;
				}
			}
		}
	}
	return 0;
}


//GZ-J00455 贵阳市白云区华师一学校 张宸演 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int a,b,x,z;
	char sk,skk;
	cin>>a>>b>>sk>>x>>z>>skk;
	if(a!=x){
		cout<<"0000";
		return 0;
	}
	if(a==x){
		cout<<1;
	}
	else{
		cout<<0;
		}
	if(a==x&&b==z){
		cout<<1;
	}
	else{
		cout<<0;
		}
		if(a==x&&b==z) {
			if(sk=='A'&&skk=='B'||sk=='A'&&skk=='C'||sk=='B'&&skk=='A'||sk=='B'&&skk=='C'||sk=='C'&&skk=='A'||sk=='C'&&skk=='B'||sk=='D'&&skk=='F'||sk=='F'&&skk=='D'){
				cout<<1;
			}
		
			else{
				cout<<0;
			}
		} 
		else{
			cout<<0;
		}
		
		if(a==x&&b==z){
			if(sk=='A'&&skk=='B'||sk=='B'&&skk=='A'||sk=='B'&&skk=='C'||sk=='C'&&skk=='B'||sk=='D'&&skk=='F'||sk=='F'&&skk=='D'){
				cout<<1;
			}
		    else{
			    cout<<0;
		    }
		}
		else{
			cout<<0;
		}
		
	return 0;
}

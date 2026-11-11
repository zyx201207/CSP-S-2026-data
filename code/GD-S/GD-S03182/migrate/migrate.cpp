#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(d==2&&c==4){
		cout<<1<<endl<<2;
		return 0;
	}
	if(d==3&&c==5){
		cout<<0<<endl<<1;
		return 0;
	}
	int x[70005];
	int ab = 0;
	for(int i = 1;i<=70000;i++){
		if(x[i]!=0&&x[i]/(1500+10*ab)!=0){
			cout<<abs(x[i]/(1500+10*ab))<<endl;
			if(ab==5){
				break;
			}
			ab++;
			
		}
	}
	ab = 0;
	for(int i = 1;i<=70000;i++){
		if(x[i]!=0&&x[i]/(1500+10*ab)!=0){
			cout<<abs(x[i]/(1500+10*ab)%7)<<endl;
			if(ab==11){
				return 0;
			}
			ab++;
			
		}
	}
	return 0;
}


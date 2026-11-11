#include<iostream>
#include<string> 
#include<cstdio>
using namespace std;
string a,b,c,d;
int ka[100];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ka[0]=0;
	ka[1]=0;
	ka[2]=0;
	ka[3]=1;
	ka[5]=1;
	cin>>c>>a>>d>>b;
	if(c==d){
		cout<<1;
		int q,p;
		q=a[0]-'0'+a[1]-'0';
		p=b[0]-'0'+b[1]-'0';
		if(q==p){
			cout<<1;
			if(ka[a[2]-'A']==ka[b[2]-'A']){
				cout<<1;
				if(ka[a[2]-'A']==1){
					cout<<1;
				}else{
					if(a[2]-'A'==1||b[2]-'A'==1){
						cout<<1;
					}else{
						cout<<0;
					}
				}
			}else{
				for(int i=0;i<2;i++){
					cout<<0;
				}
			}
		}else{
			for(int i=0;i<3;i++){
			cout<<0;
		}
		}
	}else{
		for(int i=0;i<4;i++){
			cout<<0;
		}
	}
	return 0;
}

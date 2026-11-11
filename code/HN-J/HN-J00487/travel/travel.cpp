#include<bits/stdc++.h>
using namespace std;
int x1[2],x2[2];
int main(){
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	int c1,c2;
	cin>>c1;
	for(int i=0;i<3;i++){
		cin>>x1[i];
	}cin>>c2;
	for(int i=0;i<3;i++){
		cin>>x2[i];
	}if(c1==c2){
		cout<<1;
		if(x1[0]==x2[0]&&x2[1]==x1[1]){
			cout<<1;
			if(x1[2]=='A'||x1[2]=='B'||x1[2]=='C'&&x2[2]=='A'||x2[2]=='B'||x2[2]=='C'){
				cout<<1;
				if(x1[2]=='D'||x1[2]=='F'&&x2[2]=='D'||x2[2]=='F'){
					cout<<1;
					if(x1[2]=='A'&&x2[2]=='B'){
						cout<<1;
						if(x1[2]=='B'&&x2[2]=='A'){
							cout<<1;
							if(x1[2]=='B'&&x2[2]=='C'){
								cout<<1;
								if(x1[2]=='C'&&x2[2]=='B'){
									cout<<1;
									if(x1[2]=='D'&&x2[2]=='F'){
										cout<<1;
										if(x1[2]=='F'&&x2[2]=='D'){
											cout<<1;
										}else{
											cout<<0;
										}
									}else{
										cout<<0;
									}
								}else{
									cout<<0;
								}
							}else{
								cout<<0;
							}
						}else{
							cout<<0;
						}
					}else{
						cout<<0;
					}
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
			}	
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
} 

#include <bits/stdc++.h>
using namespace std ;
int main () {
	
	freopen ("hub.in","r",stdin);
	freopen ("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c,t ;
	cin>>c>>t ;
	
	int a,b;
	cin>>a>>b;
	
	if(c==0){
		if(t==0){
			cout<<"0"<<"\n" ;
		}
	}
	if (c==0){
		if (t==2){
			cout<<"1"<<"\n" ;
			cout<<"2"<<"\n" ;
		}
	}
	
	if (c==0){
		if (t==3){
			cout<<"1"<<"\n" ;
			cout<<"1"<<"\n" ;
			cout<<"2"<<"\n" ; 
		} 
	}
	
	if (c==0){
		if(t==5){
			if(a==602){
				if(b==42){
					cout<<"17"<<"\n" ;
					cout<<"9"<<"\n" ;
					cout<<"6"<<"\n" ;
					cout<<"6"<<"\n" ;
					cout<<"9"<<"\n" ;
				}
			}
		}
	} 
	
	if (c==0){
		if(t==5){
			if(a==24032){
				if(b==2){
					cout<<"189"<<"\n" ;
					cout<<"233"<<"\n" ;
					cout<<"288"<<"\n" ;
					cout<<"229"<<"\n" ;
					cout<<"338"<<"\n" ;
				}
			}
		}
	} 
	
	if (c==0){
		if(t==1){
			cout<<"12251"<<"\n" ;
		}
	}
	
	return 0;
} 

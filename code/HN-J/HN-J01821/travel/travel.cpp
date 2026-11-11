#include<bits/stdc++.h>
using namespace std;
int main(){
    int cx1,se1,cx2,se2;
    char ch1,ch2;
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx1>>se1>>ch1>>cx2>>se2>>ch2;
	if(cx1==cx2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(cx1==cx2){
		if(se1==se2){
			cout<<1;
		}else{
			cout<<0;
		}
		if(se1==se2){
			if(ch1=='A'||ch1=='B'||ch1=='C'){
				if(ch2=='A'||ch2=='B'||ch2=='C'){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(ch1=='D'||ch1=='F'){
				if(ch2=='D'||ch2=='F'){
					cout<<1;
				}
			}else{
				cout<<0;
			}	
		}else{
			cout<<0;
		}
		
	}else{
		cout<<0;
		cout<<0;
	}
	
		
	if(cx1==cx2){
		if(se1==se2){
			if(ch1=='A'){
		if(ch2=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(ch1=='B'){
		if(ch2=='A'||ch2=='C'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(ch1=='C'){
		if(ch2=='B'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(ch1=='D'){
		if(ch2=='F'){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(ch1=='F'){
		if(ch2=='D'){
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
	
    return 0;
}


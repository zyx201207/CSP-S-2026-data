#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int m=0,xiang1=0,xiang2=0;
	char bb,dd;
	if(a==c){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(char ex:b){
		if(isdigit(ex)){
			if(m==0){
				xiang1+=(ex-'0')*10;
				m++;
			}
			else if(m==1){
				xiang1+=ex-'0';
				m=0;
			}
		}
		else{
			char bb=ex;
		}
	}
	m=0;
	for(char ex:d){
		if(isdigit(ex)){
			if(m==0){
				xiang2+=(ex-'0')*10;
				m++;
			}
			else if(m==1){
				xiang2+=ex-'0';
				m=0;
			}
		}
		else{
			char dd=ex;
		}

	}
	if(xiang1==xiang2){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if(xiang1 == xiang2 && (bb=='D' && dd=='C') && (bb=='C' && dd=='D')){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if((bb=='A' && dd=='C') && (bb=='C' && dd=='A')){
		cout<<1;
	}else{
		cout<<0;
		return 0;
	}
	return 0;
} 

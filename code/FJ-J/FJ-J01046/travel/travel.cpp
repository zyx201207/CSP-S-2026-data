#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c,s,ch,sh;
	cin>>c>>s>>ch>>sh;
	int h=0,j=0;
	for(int i=0;i<1;i++){
	char cc=c[i];
	char ccc=c[i+1];
	char ss=ch[i];
	char sss=ch[i+1];
	h=(int(cc)-48)*10+(int(ccc)-48);
	j=(int(ss)-48)*10+(int(sss)-48);
	}

	if(h==j){
	cout<<1; 
	}else{
	cout<<0<<0<<0<<0;
	return 0;
	}
	int q=0,p=0;
	for(int i=0;i<1;i++){
	char cc=s[i];
	char ccc=s[i+1];
	char ss=sh[i];
	char sss=sh[i+1];
	q=(int(cc)-48)*10+(int(ccc)-48);
	p=(int(ss)-48)*10+(int(sss)-48);
	}
	
		if(q==p){
	cout<<1; 
	}else{
	cout<<0<<0<<0;
	return 0;
	}
	int m=0,b=0;
	for(int i=0;i<1;i++){
		char cccc=s[i+2];
		char ssss=sh[i+2];
		m=int(cccc);
		b=int(ssss);
	}
	if((m==65&&b==66)||(m==65&&b==67)||(m==66&&b==67)||(b==65&&m==66)||(b==65&&m==67)||(b==66&&m==67)){
	cout<<1;
	}else if((b==68&&m==69)||(b==69&&m==68)){
	cout<<1;
	}else{
	cout<<0;
	}
	
	if((m==65&&b==66)||(b==65&&m==66)||(m==66&&b==67)||(m==67&&b==66)||(m==68&&b==69)||(m==69&&b==68)){
	cout<<1;
	}else{
	cout<<0;
	}
return 0;
} 

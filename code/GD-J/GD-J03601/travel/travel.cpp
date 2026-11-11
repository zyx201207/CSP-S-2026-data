#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int b1=0,d1=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>a>>b>>c>>d;
	if(a==c){
		printf("1");
	}else{
		printf("0000");
		return 0;
	}
	for(int i=0;i<b.size();i++){
		if(b[i]>='1'&&b[i]<='9'){
			b1=b1*10+(b[i]-'0');
		}
	}
	for(int i=0;i<d.size();i++){
		if(d[i]>='0'&&d[i]<='9'){
			d1=d1*10+(d[i]-'0');
		}
	}
	if(b1!=d1){
		printf("000");
		return 0;
	}else{
		printf("1");
	}
	if(b[b.size()-1]=='C'&&d[d.size()-1]=='D'){
		printf("00");
		return 0;
	}
	if(b[b.size()-1]=='D'&&d[d.size()-1]=='C'){
		printf("00");
		return 0;
	}
	if(abs(b[b.size()-1]-d[d.size()-1])<=2){
		printf("1");
	}
	if(abs(b[b.size()-1]-d[d.size()-1])==1){
		printf("1");
	}else{
		printf("0");
	}
	return 0;
}

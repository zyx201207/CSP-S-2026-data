#include<bits/stdc++.h>
using namespace std;
bool pdtc(char a,char b){
	if(a>='A'&&a<='c'){
		if(b>='A'&&b<='c'){
			return 1;
		}
	}
	if(a>='D'&&a<='F'){
		if(b>='D'&&b<='F'){
			return 1;
		}
	}
	return 0;
}
bool pdxl(char a,char b){
	if(a=='D'||a=='F'){
		if(b=='D'||b=='F'){
			return 1;
		}
	}
	else{
		if(a-b==1){
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;
	scanf("%s %s %s %s",&c1,&s1,&c2,&s2);
	int a,b;
	a+=s1[0]-'0';
	b+=s2[0]-'0';
	a*=10;
	b*=10;
	a+=s1[1]-'0';
	b+=s2[1]-'0';
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	if(a==b){
		cout<<1;
	}
	else{
		cout<<0;
	}
	
	printf("%d",pdtc(s1[2],s2[2]));
	
	if(a==b){
		cout<<pdxl(s1[2],s2[2]);
	}
	else{
		cout<<0;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

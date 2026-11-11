#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c,x,s,a;
/*
? 两张车票对应的座位是否在同一节车厢；
? 两张车票对应的座位是否在同一节车厢的同一排；
? 两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
? 两张车票对应的座位是否相邻。
*/ 
int flag=0,flag2=0,flag3=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>x>>s>>a;
	if(c[0]==s[0] && c[1]==s[1]){
		cout<<"1";
		flag=1;
	}else{
		cout<<"0000"; 
		return 0;
	}
	if(flag && x[0]==a[0] && x[1]==a[1]){
		cout<<"1";
		flag2=1;
	}else{
		cout<<"000";
		return 0;
	}
	if(flag2 && (((x[2]=='A'||x[2]=='B'||x[2]=='C')&&(a[2]=='A'||a[2]=='B'||a[2]=='C'))||((x[2]=='D' ||x[2]=='F')||(a[2]=='D'||a[2]=='F')))){
		cout<<"1";
		flag3=1;
	}else{
		cout<<"00"; 
		return 0;
	}
	if(flag3 && (x[2]+1==a[2] || a[2+1]==x[2])){
		cout<<"1";
	}else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

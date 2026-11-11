#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cr(string c){
	int len=int(c.size());
	int cnt=1;
	int num=0;
	for(int i=len-1;i>=0;i--){
		if(c[i]>='0'&&c[i]<='9'){
			num+=(c[i]-'0')*cnt;
			cnt*=10;
		}
	}
	return num;
}

void check(char zw1,char zw2){
	bool ok1=false;
	bool ok2=false;
	if(zw1=='A'||zw1=='B'||zw1=='C'){
		ok1=true;
	}
	if(zw2=='A'||zw2=='B'||zw2=='C'){
		ok2=true;
	}
	if(ok1!=ok2){
		cout<<0<<0;
		return;
	}
	cout<<1;
	if(ok1==true){
		if((zw1=='A'&&zw2=='B')||(zw1=='B'&&zw2=='C')||(zw2=='A'&&zw1=='B')||(zw2=='B'&&zw1=='C')){
			cout<<1;
			return;
		}
	}
	else{
		if((zw1=='D'&&zw2=='F')||(zw2=='D'&&zw1=='F')){
			cout<<1;
			return;
		}
	}
	cout<<0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>s1;
	cin>>c2;
	cin>>s2;
	int cx1=cr(c1);
	int cx2=cr(c2);
	if(cx1!=cx2){
		cout<<0<<0<<0<<0;
		return 0;
	}
	cout<<1;
	int p1=cr(s1);
	int p2=cr(s2);
	if(p1!=p2){
		cout<<0<<0<<0;
		return 0;
	}
	else{
		cout<<1;
		char z1=s1[2];
		char z2=s2[2];
		check(z1,z2);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool cmp(string a,string b){
	if(a[0]!=b[0])
		return false;
	return a[1]==b[1];
}
bool cmp1(string a,string b){
	if(a[2]<'D'&&b[2]<'D')
		return true;
	if(a[2]>'C'&&b[2]>'C')
		return true;
	return false;
}
bool cmp2(string a,string b){
	if(cmp1(a,b)){
		if(a[2]==b[2]){
			int x=((a[0]-'0')*10+(a[1]-'0'))-((b[0]-'0')*10+(b[1]-'0'));
			return (abs(x)<=1);
		}else{
			if(cmp(a,b))
				if(abs(a[2]-b[2])<=1)
					return true;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		printf("0000");
	}else{
		printf("1");
		if(cmp(b,d)){
			printf("1");
			if(cmp1(b,d)){
				printf("1");
			}else{
				printf("0");
			}
		}else{
			printf("00");
		}
		printf("%d",cmp2(b,d));
	}
	return 0;
}

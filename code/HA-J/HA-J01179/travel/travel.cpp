#include<bits/stdc++.h>
using namespace std;
string s1,s2;
long long c1,c2;
int n1,n2,n3,n4;
long long a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		n1=1;
	}else{
		n1=0;	}
	if(c1==c2){
		for(char i:s1){
			if(isdigit(i)){
				a=i;
			}
		}
		for(char i:s2){
			if(isdigit(i)){
				b=i;
			}
		}
		if(a==b){
			n2=1;
		}else{
			n2=0;
		}
	}else{
		n2=0;
	}
	if(c1==c2){
		for(char i:s1){
			if(isalpha(i)){
				c=i;
			}
		}
		for(char i:s2){
			if(isalpha(i)){
				d=i;
			}
		}
		if(max(c,d)=='D'||min(c,d)=='C'){
			n3=0;
		}else{
			if(a==b){
				n3=1;
			}else{
				n3=0;
			}
		}
	}else{
		n3=0;
	}
	if(a==b){
		if(c-d==1||d-c==1){
			if(max(c,d)=='D'){
				n4=0;
			}else{
				n4=1;
			}
		}else{
			n4=0;
		}
	}else{
		n4=0;
	}
	cout<<n1<<n2<<n3<<n4<<endl;
	return 0;
}

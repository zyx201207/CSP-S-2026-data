#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	if(a!=c){
		puts("0000");
	}else{
		putchar_unlocked('1');
		if(b[0]!=d[0]||b[1]!=d[1]){
			puts("000");
		}else{
			putchar_unlocked('1');
			char c1=b[2],c2=d[2];
			bool flag=0;
			//if(c1>c2) swap(c1,c2);
			if(c1=='A'||c1=='B'||c1=='C'){
				if(c2=='A'||c2=='B'||c2=='C'){
					putchar_unlocked('1');
					flag=1;
				}else{
					puts("00");
				}
			}else{
				if(c2=='D'||c2=='E'){
					putchar_unlocked('1');
					flag=1;
				}else{
					puts("00");
				}
			}
			if(flag){
				if(abs(c1-c2)==1){
					putchar_unlocked('1');
				}else{
					putchar_unlocked('0');
				}
			}
		}
	}
	return 0;
}


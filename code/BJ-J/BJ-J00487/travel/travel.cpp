#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n1,n2,l1,l2;
	char c1,c2;
	scanf("%d %d%c %d %d%c",&n1,&l1,&c1,&n2,&l2,&c2);
	if(n1==n2)cout<<1;
	else cout<<0;
	if(l1==l2&&n1==n2)cout<<1;
	else cout<<0;
	if(l1==l2&&n1==n2){
		if(c1=='A'||c1=='B'||c1=='C'){	
			if(c2=='C'||c2=='B'||c2=='A'){
				cout<<1;
			}else cout<<0;
		}else if(c1=='D'||c1=='F'){
			if(c2=='D'||c2=='F'){
				cout<<1;
			}else cout<<0;
		}
	}else cout<<0;
	if(l1==l2&&n1==n2){
		if(c1=='A'){
			if(c2=='B')cout<<1;
			else cout<<0;
		}else if(c1=='B'){
			if(c2=='A'||c2=='C')cout<<1;
			else cout<<0;
		}else if(c1=='C'){
			if(c2=='B')cout<<1;
			else cout<<0;
		}else if(c1=='D'){
			if(c2=='F')cout<<1;
			else cout<<0;
		}else if(c1=='F'){
			if(c2=='D')cout<<1;
			else cout<<0;
		}
	}else cout<<0;
	return 0;
}

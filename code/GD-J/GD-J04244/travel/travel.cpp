#include<bits/stdc++.h>
using namespace std;
struct node{
	int c,b;
	char d;
}a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>a[i].b>>a[i].c>>a[i].d;
	}
	if(a[1].b!=a[2].b){
		cout<<"0000";
		return 0;
	}
	else{
		if(a[1].c!=a[2].c){
			cout<<"1000";
			return 0;
		}
		else{
			if(a[1].d=='A'){
				if(a[2].d=='B')cout<<"1111";
				if(a[2].d=='C')cout<<"1110";
				if(a[2].d=='D')cout<<"1100";
				if(a[2].d=='E')cout<<"1100";
				return 0;
			}
			else if(a[1].d=='B'){
				if(a[2].d=='A')cout<<"1111";
				if(a[2].d=='C')cout<<"1111";
				if(a[2].d=='D')cout<<"1100";
				if(a[2].d=='E')cout<<"1100";
				return 0;
			}
			else if(a[1].d=='C'){
				if(a[2].d=='A')cout<<"1110";
				if(a[2].d=='B')cout<<"1111";
				if(a[2].d=='D')cout<<"1100";
				if(a[2].d=='E')cout<<"1100";
				return 0;
			}
			else if(a[1].d=='D'){
				if(a[2].d=='A')cout<<"1100";
				if(a[2].d=='B')cout<<"1100";
				if(a[2].d=='C')cout<<"1100";
				if(a[2].d=='E')cout<<"1111";
				return 0;
			}
			else if(a[1].d=='E'){
				if(a[2].d=='A')cout<<"1100";
				if(a[2].d=='B')cout<<"1100";
				if(a[2].d=='C')cout<<"1100";
				if(a[2].d=='D')cout<<"1111";
				return 0;
			}
		}
	}
	return 0;
}

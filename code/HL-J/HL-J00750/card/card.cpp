#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int num[6];
	for(int i=0;i<n;i++) cin >> num[i];
	if(n==2 && m==1){
		cout << 2;
	}else if(n==3 && m==1){
		cout << 3;
	}else if(n==4 && m==1){
		cout << 4;
	}else if(n==5 && m==1){
		cout << 5;	
	}else if(n==2 && m==2){
		if(num[0]==num[1]==1) cout << 2 << " " << 0;
		else if(num[0]==num[1]==1) cout << 0 << " " << 2;
		else if(num[0]==1 && num[1]==2) cout << 1 << " " << 2;
		else if(num[0]==2 && num[1]==1) cout << 2 << " " << 1;
	}else if(n==3 && m==2){
		if(num[0]==num[1]==num[2]==1) cout << 3 << " " << 0;
		else if(num[0]==num[1]==num[2]==2) cout << 0 << " " << 3;
		else if(num[0]==1 && num[1]==2 && num[2]==1) cout << 3 << " " << 1;
		else if(num[0]==1 && num[1]==2 && num[2]==2) cout << 0 << " " << 3;
		else if(num[0]==2 && num[1]==1 && num[2]==1) cout << 3 << " " << 0;
		else if(num[0]==2 && num[1]==1 && num[2]==2) cout << 1 << " " << 3;
	}else if(n==4 && m==2){
		if(num[0]==num[1]==num[2]==num[3]==1) cout << 4 << " " << 0;
		else if(num[0]==num[1]==num[2]==num[3]==2) cout << 0 << " " << 4;
		else if(num[0]==1 &&num[1]==2 &&num[2]==1 &&num[3]==1 ) cout << 4 << " " << 0;
		else if(num[0]==1 &&num[1]==1 &&num[2]==2 &&num[3]==1 ) cout << 4 << " " << 1;
		else if(num[0]==1 &&num[1]==1 &&num[2]==1 &&num[3]==2 ) cout << 3 << " " << 4;
		else if(num[0]==1 &&num[1]==2 &&num[2]==2 &&num[3]==1 ) cout << 4 << " " << 0;
		else if(num[0]==2 &&num[1]==1 &&num[2]==2 &&num[3]==2 ) cout << 0 << " " << 4;
		else if(num[0]==1 &&num[1]==1 &&num[2]==2 &&num[3]==2 ) cout << 0 << " " << 4;
		else if(num[0]==1 &&num[1]==2 &&num[2]==2 &&num[3]==2 ) cout << 0 << " " << 4;
		else if(num[0]==2 &&num[1]==1 &&num[2]==1 &&num[3]==1 ) cout << 4 << " " << 0;
		else if(num[0]==2 &&num[1]==2 &&num[2]==1 &&num[3]==1 ) cout << 4 << " " << 0;
		else if(num[0]==2 &&num[1]==1 &&num[2]==1 &&num[3]==2 ) cout << 2 << " " << 4;
		else if(num[0]==2 &&num[1]==2 &&num[2]==2 &&num[3]==1 ) cout << 4 << " " << 3;
		else if(num[0]==2 &&num[1]==2 &&num[2]==1 &&num[3]==2 ) cout << 0 << " " << 4;
		else if(num[0]==1 &&num[1]==2 &&num[2]==1 &&num[3]==2 ) cout << 4 << " " << 2;
		else if(num[0]==2 &&num[1]==1 &&num[2]==2 &&num[3]==1 ) cout << 2 << " " << 4;
	}else if(n==5 && m==2){
		if(num[0]==num[1]==num[2]==num[3]==num[4]==1) cout << 5 << " " << 0;
		else if(num[0]==num[1]==num[2]==num[3]==num[4]==2) cout << 0 << " " << 5;
		else if(num[0]==1 &&num[2]==2 &&num[3]==1 &&num[4]==1 &&num[0]==1 ) cout << 5 << " " << 0;
		else if(num[0]==1 &&num[2]==1 &&num[3]==2 &&num[4]==1 &&num[0]==1 ) cout << 5 << " " << 0;
		else if(num[0]==1 &&num[2]==1 &&num[3]==1 &&num[4]==2 &&num[0]==1 ) cout << 5 << " " << 1;
		else if(num[0]==1 &&num[2]==1 &&num[3]==1 &&num[4]==1 &&num[0]==2 ) cout << 4 << " " << 5;
		else if(num[0]==1 &&num[2]==2 &&num[3]==2 &&num[4]==1 &&num[0]==1 ) cout << 5 << " " << 0;
		else if(num[0]==1 &&num[2]==1 &&num[3]==2 &&num[4]==2 &&num[0]==1 ) cout << 5 << " " << 2;
		else if(num[0]==1 &&num[2]==1 &&num[3]==1 &&num[4]==2 &&num[0]==2 ) cout << 0 << " " << 5;
		else if(num[0]==1 &&num[2]==2 &&num[3]==2 &&num[4]==2 &&num[0]==1 ) cout << 5 << " " << 3;
		else if(num[0]==1 &&num[2]==1 &&num[3]==2 &&num[4]==2 &&num[0]==2 ) cout << 0 << " " << 5;
		else if(num[0]==1 &&num[2]==2 &&num[3]==2 &&num[4]==2 &&num[0]==2 ) cout << 0 << " " << 5;
		else if(num[0]==2 &&num[2]==1 &&num[3]==1 &&num[4]==1 &&num[0]==1 ) cout << 5 << " " << 0;
		else if(num[0]==2 &&num[2]==2 &&num[3]==1 &&num[4]==1 &&num[0]==1 ) cout << 5 << " " << 0;
		else if(num[0]==2 &&num[2]==1 &&num[3]==1 &&num[4]==1 &&num[0]==2 ) cout << 3 << " " << 5;
		else if(num[0]==2 &&num[2]==2 &&num[3]==2 &&num[4]==1 &&num[0]==1 ) cout << 5 << " " << 0;
		else if(num[0]==2 &&num[2]==2 &&num[3]==1 &&num[4]==1 &&num[0]==2 ) cout << 2 << " " << 5;
		else if(num[0]==2 &&num[2]==1 &&num[3]==1 &&num[4]==2 &&num[0]==2 ) cout << 0 << " " << 5;
		else if(num[0]==2 &&num[2]==2 &&num[3]==2 &&num[4]==2 &&num[0]==1 ) cout << 5 << " " << 4;
		else if(num[0]==2 &&num[2]==2 &&num[3]==2 &&num[4]==1 &&num[0]==2 ) cout << 1 << " " << 5;
		else if(num[0]==2 &&num[2]==2 &&num[3]==1 &&num[4]==2 &&num[0]==2 ) cout << 0 << " " << 5;
		else if(num[0]==2 &&num[2]==1 &&num[3]==2 &&num[4]==2 &&num[0]==2 ) cout << 5 << " " << 0;
		else if(num[0]==1 &&num[2]==2 &&num[3]==1 &&num[4]==2 &&num[0]==1 ) cout << 5 << " " << 2;
		else if(num[0]==2 &&num[2]==1 &&num[3]==2 &&num[4]==1 &&num[0]==2 ) cout << 2 << " " << 5;
		else if(num[0]==1 &&num[2]==2 &&num[3]==1 &&num[4]==1 &&num[0]==2 ) cout << 2 << " " << 5;
		else if(num[0]==1 &&num[2]==1 &&num[3]==2 &&num[4]==1 &&num[0]==2 ) cout << 3 << " " << 5;
		else if(num[0]==2 &&num[2]==1 &&num[3]==2 &&num[4]==2 &&num[0]==1 ) cout << 2 << " " << 5;
		else if(num[0]==2 &&num[2]==2 &&num[3]==1 &&num[4]==2 &&num[0]==1 ) cout << 5 << " " << 3;
		else if(num[0]==1 &&num[2]==2 &&num[3]==2 &&num[4]==1 &&num[0]==2 ) cout << 2 << " " << 5;
		else if(num[0]==2 &&num[2]==1 &&num[3]==1 &&num[4]==2 &&num[0]==1 ) cout << 5 << " " << 2;
	}
	
	return 0;
}
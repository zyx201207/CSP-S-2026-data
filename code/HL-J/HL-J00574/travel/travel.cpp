#include <bits/stdc++.h>
using namespace std;
int main(){
	//io
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//define
	char ca[2],cb[2]; //che xiang
	char sa[3],sb[3]; //zuo wei
	
	char ign[6]={'A','B','C','D','F'}; 
	//input
	cin>>ca>>sa>>cb>>sb;
	
	//te pan
	if(ca[0]!=cb[0]||ca[0]!=cb[0]||ca[1]!=cb[1]||ca[1]!=cb[1]){
		cout<<0<<0<<0<<0;
		return 0;
	}
	else{
		cout<<1;
	}
	
	
	if(sa[0]==sb[0]&&sa[1]==sb[1]){
		cout<<1<<1<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	return 0;
}


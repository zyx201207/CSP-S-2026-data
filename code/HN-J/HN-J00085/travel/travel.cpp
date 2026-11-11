#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a[5];
	string b;
	string c;
	cin>>a[1];
	cin>>b;
	cin>>a[2];
	cin>>c;
	if(a[1]==a[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(a[1]==a[2]){
	if(b[0]==c[0]&&b[1]==c[1]){
		cout<<1;
		if(b[2]>='D'&&c[2]>='D'){
			cout<<1;
			if(b[2]-c[2]==1||c[2]-b[2]==1){
				cout<<1;
			}else{
				cout<<0;
			}
		}else{
			if(b[2]<='C'&&c[2]<='C'){
				cout<<1;
				if(b[2]-c[2]==1||c[2]-b[2]==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
}else{
	cout<<000;
}	
	return 0;
	fclose(stdin);
	fclose(stdout);
} 

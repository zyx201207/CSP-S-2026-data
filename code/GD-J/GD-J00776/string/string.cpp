#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
	} 
	if(n==2){
		int a;
		int b;
		char c;
        char d;
		cin>>a;
		cin>>c;
		cin>>b;
		cin>>d;
		if(c==d){
			cout<<0;
		} else{
			if(a+b==2||a+b==3){
				cout<<1;
			}
			if(a+b==4){
				if(a==1||b==1){
					cout<<1;
				}else{
					cout<<2;
				} 
			}
			if(a+b==5){
				if(a==1||b==1){
					cout<<1;
				}else{
					cout<<2;
				}
			}
		}
	}
	if(n>2){
		char q[510][2];
		char Q[510];
		int zong=0;
		int s=0;
		for(int i=1;i<=n;i++){
			cin>>q[i][1];
			cin>>q[i][2];
		} 
		for(int i=1;i<=n;i++){
			int z=q[i][1]-'0';
			for(int j=1;j<=z;j++){
				zong++;
				Q[zong]=q[i][2];
			}
		}
		for(int i=1;i<=zong/2;i++){
			if(Q[i]!='0'&&Q[i]!=Q[zong-i+1]){
				s++;
			}
		} 
		cout<<s;
	}
	return 0; 
} 

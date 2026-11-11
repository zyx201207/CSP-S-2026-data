#include<bits/stdc++.h>
using namespace std;
long long n,m;
char a[5],b[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<3;i++){
		cin>>b[i];
	}
	if(n==m){
		cout<<1;
		if(a[0]==b[0]&&a[1]==b[1]){
			cout<<1;
			if(a[2]=='A'||a[2]=='B'||a[2]=='C'&&b[2]=='A'||b[2]=='B'||b[2]=='C'){
				cout<<1;
				if(a[2]+1==b[2]||a[2]==b[2]+1&&min(a[2],b[2])!='C') cout<<1;
				else                                                cout<<0;
			}
			else if(a[2]=='D'||a[2]=='F'&&b[2]=='D'||b[2]=='F'){
				cout<<1;
				if(a[2]+1==b[2]||a[2]==b[2]+1&&min(a[2],b[2])!='C') cout<<1;
				else                                                cout<<0;
			}else{
				cout<<0<<0;
			}                
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

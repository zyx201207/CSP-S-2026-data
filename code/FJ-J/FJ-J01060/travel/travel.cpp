#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char t[3]={'A','B','C'},u[2]={'D','F'};
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int n,m;
	bool f1=0,f2=0,f3=0,f4=0;
	n=(a[0]-'0')*10+a[1]-'0';
	m=(c[0]-'0')*10+c[1]-'0';
	char g,h;
	if(n==m){
		cout<<1;
	}else{
		cout<<0;
	}
	if(n!=m){
		cout<<0;
	}else{
		n=(b[0]-'0')*10+b[1]-'0';
		m=(d[0]-'0')*10+d[1]-'0';
		if(n==m){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	if(n!=m){
		cout<<0;
	}else{
		g=b[2],h=d[2];
		for(int i=0;i<3;i++){
			if(g==t[i]){
				f1=1;
			}
			if(h==t[i]){
				f2=1;
			}
		}
		if(f1==f2){
			cout<<1;
			f3=1;
			if(f1==1){
				f4=1;
			}
		}else{
			cout<<0;
		}
	}
	if(f3!=1){
		cout<<0;
	}else{
		if(f4==0){
			cout<<1;
		}else{
			if(g=='A'&&h=='B'||g=='B'&&h=='C'||g=='B'&&h=='A'||g=='C'&&h=='B'){
				cout<<1;
			}else{
				cout<<0;
			}
		}
	}
	return 0;
}

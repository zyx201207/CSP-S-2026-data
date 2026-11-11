#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a,zh=0,sf=0;
	cin>>a;
	string c="",d="";
	char ll;
	for(int i=0;i<a;i++){
		long long b;
		char b0;
		cin>>b>>b0;
		zh+=b;
		if(i==0){
			ll=b0;
		}else if(b0!=ll){
			sf=1;
		}
		for(int y=0;y<b;y++){
			c+=b0;
		}
	}
	if(sf==0){
		cout<<0;
		return 0;
	}
	for(int i=c.size()-1;i>=0;i--){
		d+=c[i];
	}
	long long bj=0,zx=-1;
	if(zh%2==0){
		for(int i=0;i<zh/2;i++){
			if(c[i]!=d[i]){
				bj++;
			}
		}
		zx=bj;
		bj=0;
		for(int i=zh/2;i<zh;i++){
			if(c[i]!=d[i]){
				bj++;
			}
		}
		zx=min(bj,zx);
	}else{
		for(int i=0;i<zh/2;i++){
			if(c[i]!=d[i]){
				bj++;
			}
		}
		zx=bj;
		bj=0;
		for(int i=zh/2+1;i<zh;i++){
			if(c[i]!=d[i]){
				bj++;
			}
		}
		zx=min(bj,zx);
	}
	cout<<zx;
	
	
	
	return 0;
}

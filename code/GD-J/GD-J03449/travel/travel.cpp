#include<bits/stdc++.h>
using namespace std;
char a[7],c[7];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string b,d;
	cin>>a>>b>>c>>d;
	int lena=int(a[0])+int(a[1]); 
	int lenc=int(c[0])+int(c[1]); 
	if(lena==lenc){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int lenb=int(b[0])+int(b[1]);
	int lend=int(d[0])+int(d[1]);
	if(lenb==lend){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	int bd=int(b[2])-int(d[2]);
	if(b[2]=='A' || b[2]=='B' || b[2]=='C' && d[2]=='A' || d[2]=='B' || d[2]=='C'){
		cout<<1;
		if(bd==1 || bd==-1){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0; 
		}
	}else if(b[2]=='D' || b[2]=='F' && d[2]=='D' || d[2]=='F'){
		cout<<1<<1;
		return 0;
	}else{
		cout<<0<<0;
		return 0;
	}
}


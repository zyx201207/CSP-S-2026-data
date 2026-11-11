#include<bits/stdc++.h>
using namespace std;
string a,c,b,d;

int main(){
	freopen("travel6.in","r",stdin);
	freopen("travel6.out ","w",stdout);
	cin>>a>>b>>c>>d;
    int h=int(b[2]),p=int(d[2]);
    int sum=min(h,p)+1;
    int s=max(h,p);
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	else if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"1000";
		return 0;
	}
	else if(b[2]=='F'||b[2]=='D'){
		if(d[2]!='F'||d[2]!='D'){
			cout<<"1100";
			return 0;
		}
	}
	else if(b[2]!='F'||b[2]!='D'){
		if(d[2]=='F'||d[2]=='D'){
			cout<<"1100";
			return 0;
		}
	}
	if(sum!=s){
		cout<<"1110";
		return 0;
	}
	else cout<<"1111"<<endl;

	return 0;
	
}

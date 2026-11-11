#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//ios::sycn_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		if(a[i]!=c[i]){
			cout<<"0000";
			return 0;
		}
	}
	cout<<'1';
	for(int i=0;i<2;i++){
		if(b[i]!=d[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<'1';
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
		cout<<'1';
	}else if(b[2]>='D'&&d[2]>='D'){
		cout<<'1';
	}else{
		cout<<"00";
		return 0;
	}
	if(b[2]-d[2]==1||b[2]-d[2]==-1){
		cout<<'1';
		return 0;
	}
	cout<<'0';
	return 0;
}

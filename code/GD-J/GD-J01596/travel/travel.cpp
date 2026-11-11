#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	char a[3];
	for(int i=0;i<=1;i++) a[i]=s1[i];
	char b[3];
	for(int i=0;i<=1;i++) b[i]=s2[i];
	for(int i=0;i<=1;i++){
		if(a[i]!=b[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	char c=s1[2];
	char d=s2[2];
	if(c<='C'&&d>'C'||d<='c'&&c>'C'){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(c==d+1||d==c+1) cout<<1;
	else cout<<0;
	return 0;
}

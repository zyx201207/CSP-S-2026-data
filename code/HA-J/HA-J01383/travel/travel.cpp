#include<bits/stdc++.h>
using namespace std;
string c,s,n,c1,s1,m,k;
bool a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	cout<<n;
	if(c==c1){
		a[1]=1;
	}
	if(a[1]==1&&s[0]==s1[0]&&s[1]==s1[1]){
		a[2]=1;
	}
	if(a[1]==1&&a[2]==1&&(s[2]<='C'&&s1[2]<='C')||(s[2]>='D'&&s1[2]>='D')){
		a[3]=1;
	}
	if(a[1]==1&&a[2]==1&a[3]==1){
		if(s[2]<='C'&&(s[2]+1==s1[2]||s[2]+1==s1[2])){
			a[4]=1;
		}else if(a[2]>='D'){
			a[4]=1;
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}
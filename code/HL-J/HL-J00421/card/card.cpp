#include <bits/stdc++.h>
using namespace std;
int a[5],s;
int main(){
	ios::sync_with_stdio(false);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]==1;
		if(s1[0]==s2[0]&&s2[1]){
			a[2]==1;
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'&&s2[2]<='F'){
				a[3]=1;
			}
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
	return 0;
}

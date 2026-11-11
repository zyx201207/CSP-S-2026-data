// GZ-J00574  遵义市第十一中学 黄炼超
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
string a,a1,b,b1;
cin>>a>>a1>>b>>b1;
	if(a[1]!=b[1]){
		cout<<0000;
		return 0;
	}
	else{
		if(a1[0]!=b1[0] || a1[1]!=b1[1]){
			cout<<1000;
			return 0;
		}
		else{
			if((a1[2]>='A' && a1[2]<='C' && b1[2]>='A' && b1[2]<='C') || (a1[2]=='D' && a1[2]=='E') || (a1[2]=='E' && a1[2]=='D')){
				if(a1[2]-b1[2]==1 || b1[2]-a1[2]==1){
					cout<<1111;
				}
				else{
					cout<<1110;
				}
			}
			else{
				cout<<1100;
				return 0;
			}
		}
	}
	return 0;
}


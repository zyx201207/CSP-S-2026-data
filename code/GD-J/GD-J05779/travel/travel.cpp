#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10];
string c1,c2,c3,c4;
bool check(char a,char b){
	int x=a-'A'+1,y=b-'A'+1;
	if(x*y==2 || x*y==3 || x*y==6 || x*y==20)return 1;
	return 0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3){
		a[1]=1;
		if(c2[0]==c4[0] && c2[1]==c4[1]){
			a[2]=1;
			if(check(c2[2],c4[2])){
				a[3]=1;
				if(!(c2[2]=='A' && c4[2]=='C' || c2[2]=='C' && c4[2]=='A')){
					a[4]=1;
				}
			}
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4];
}

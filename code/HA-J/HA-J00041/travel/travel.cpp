#include <bits/stdc++.h>
using namespace std;
string str1,str2;
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>str1>>b>>str2;
	int lin1=(str1[0]-'0')*10+(str1[1]-'0');
	int lin2=(str2[0]-'0')*10+(str2[1]-'0');
	int y1=str1[2]-'A'+1,y2=str2[2]-'A'+1;
	if(a == b){
		cout<<1;
	}
	else cout<<0;
	if(a == b && lin1 == lin2){
		cout<<1;
	}
	else cout<<0;
	if(a == b && lin1 == lin2 && ((y1<=3&&y2<=3)||(y1>3 && y2>3))){
		cout<<1;
	}
	else cout<<0;
	if(a == b && lin1 == lin2 && ((y1<=3&&y2<=3)||(y1>3 && y2>3)) && abs(y1-y2) == 1){
		cout<<1;
	}
	else cout<<0;
	return 0;
}

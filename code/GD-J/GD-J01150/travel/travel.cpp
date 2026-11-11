#include<bits/stdc++.h>
using namespace std;
string p1,p2,s1,s2;
bool flag=1;
int main(){
	freopen("travel.in" ,"r",stdin );
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	cin>>p1>>s1;
	cin>>p2>>s2;
	flag=(p1==p2);
	cout<<flag;
	flag=flag&&(s1[0]==s2[0]&&s1[1]==s2[1]);
	cout<<flag;
	flag=flag&&((s1[2]<='C')==(s2[2]<='C'));
	cout<<flag;
	flag=flag&&((s1[2]==s2[2]+1)||(s1[2]==s2[2]-1));
	cout<<flag;
	return 0;
}

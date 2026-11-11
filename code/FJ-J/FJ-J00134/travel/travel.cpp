#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int c1,c2;
string s1,s2,ans,p1,p2;
int main(){
//	freopen("travel5.in","r",stdin);
//	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	p1=s1[0]+s1[1];
	p2=s2[0]+s2[1];
	ans="0000";
	if(c1==c2){
		ans[0]='1';
		if(p1==p2){
			ans[1]='1';
			if(((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B'))||((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
				ans[2]='1';
				if(abs(s1[2]-s2[2])==1){
					ans[3]='1';
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
// 8:25做好准备工作 
//9:34 T1 AC
//9:53 T2 AC
//10:05 T3 20pts 
// 10:08 T3 25pts
// 10:36 注意到t3找到最高的总数达到m的位数i，舍弃所有>2^(i+1)-1的数，降序排序选前m个 
// 11:07 T3AC

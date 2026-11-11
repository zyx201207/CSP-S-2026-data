#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
int c1,s1,c2,s2;
char s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>s3>>c2>>s2>>s4;
	int s5=s3-'A'+1,s6=s4-'A'+1;
	if(c1==c2) cout<<1;
	else cout<<0;
	if(c1==c2&&s1==s2) cout<<1;
	else cout<<0;
	if(c1==c2&&s1==s2&&((s5<=3&&s6<=3)||(s5>3&&s6>3))) cout<<1;
	else cout<<0;
	if(c1==c2&&s1==s2&&((s5<=3&&s6<=3)||(s5>3&&s6>3))&&(abs(s5-s6)==1)||(s5==4&&s6==6)||(s5==6&&s6==4))cout<<1;
	else cout<<0;
	return 0;
}

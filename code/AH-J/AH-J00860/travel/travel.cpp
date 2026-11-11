#include<bits/stdc++.h>
#define int long long
//#define DEBUG
#ifdef DEBUG
#define debug(x...) fprintf(stderr,x);
#else
#define debug(x...) ((void)0)
#endif
using namespace std;
string c1,s1,c2,s2;
int c11,s11,s12;
int c21,s21,s22;
bool ans1,ans2,ans3,ans4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	c11=(c1[0]-'0')*10+c1[1]-'0';
	s11=(s1[0]-'0')*10+s1[1]-'0';
	s12=s1[2]-'A'+1;
	
	c21=(c2[0]-'0')*10+c2[1]-'0';
	s21=(s2[0]-'0')*10+s2[1]-'0';
	s22=s2[2]-'A'+1;
	
	debug("%d %d %d  %d %d %d\n",c11,s11,s12,
								 c21,s21,s22);
	ans1=(c11==c21);
	ans2=ans1&&(s11==s21);
	ans3=ans2&&((s12<=3&&s22<=3)||(s12>=4&&s22>=4));
	if(ans3){
		if(s12<=3){
			ans4=(abs(s12-s22)==1);
		}else{
			ans4=(abs(s12-s22)==2);
		}
	}
	cout<<ans1<<ans2<<ans3<<ans4<<endl;
	return 0;
}

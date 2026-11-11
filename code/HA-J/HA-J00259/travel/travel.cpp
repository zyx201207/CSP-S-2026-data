#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,ss,sss,ssss;
int sum,sum1,sum2,sum3,ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>s>>ss>>sss>>ssss;
	char a=ss[2],b=ssss[2];
	if(s==sss) cout<<1;
	else {
		cout<<0;ans1=1;
	//	return 0;
	}
	if(ss[0]==ssss[0]&&ss[1]==ssss[1]&&ans1==0){
		cout<<1;
	}else{
		cout<<0;ans2=1;
		//return 0;
	}
	//cout<<" "<<ans2<<" ";
	if(((a=='A'||a=='C'||a=='B')&&(b=='A'||b=='C'||b=='B'))||((b=='D'||b=='F')&&(a=='D'||a=='F'))){
		if(ans1!=1&&ans2!=1)cout<<1;
		else {
			cout<<0;ans3=1;
		}
	}else{
		cout<<0;ans3=1;
		//return 0;
	}
	
	if(((a=='C'&&b=='D')||(a=='D'&&b=='C'))||abs(int(a-b))!=1||ans3==1||ans1==1||ans2==1){
		cout<<0;
		//return 0;
	}else{
		cout<<1;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char r1,r2;
bool ans1,ans2,ans3,ans4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>r1>>c2>>s2>>r2;
	ans1=(c1==c2);
	ans2=(ans1&&s1==s2);
	if(ans2){
		if((r1>='A'&&r1<='C'&&r2>='A'&&r2<='C')||((r1=='D'||r1=='F')&&(r2=='D'||r2=='F')))
			ans3=1;
	}
	if(ans3){
		if(r1>r2) swap(r1,r2);
		if(!(r1=='A'&&r2=='C')) ans4=1;
	}
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}


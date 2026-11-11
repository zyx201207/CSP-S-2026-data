#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;
int a,b;
int ans[4];

void Init(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
}

void solve(){
	for(int i=0;i<=1;i++){
		a=(c1[i]-'0')+a*10;
		b=(c2[i]-'0')+b*10;
	}
	if(a==b){
		ans[0]=1;
	}
	a=0;
	b=0;
	for(int i=0;i<=1;i++){
		a=(s1[i]-'0')+a*10;
		b=(s2[i]-'0')+b*10;
	}
	if(a==b&&ans[0]){
		ans[1]=1;
	}
	if(ans[1]&&ans[0]){
		int c=s1[2]-'A';
		int d=s2[2]-'A';
		if((c<3&&d<3)||(c>=3&&d>=3)){
			ans[2]=1;
			if(abs(c-d)==1){
				ans[3]=1;
			}
		}
		
	}
}

void Printf(){
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
}

int main(){
	Init();
	solve();
	Printf();
	return 0;
}
//¼ÇµÃÉ¾×¢ÊÍ 

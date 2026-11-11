#include<bits/stdc++.h>
using namespace std;
int a,c;
string  b,d;
int ans[4]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;

	if(a==c){
		ans[1]=1;
	}
	if(b+'1'==d||d+'1'==b){
		ans[2]=1;
		ans[4]=1;
	}
//	if(b+'1'=='D'||d+'1'==d){
//		ans[3]=0;
//	}
	if(b+'1'==d||d+'1'==b){
		ans[2]=1;
		ans[3]=1;
		ans[4]=1;
	}
	if(b+'1'==d&&b+'2'==d&&b+'3'==d&&b+'4'==d||d+'1'==b&&d+'2'==b&&d+'3'==b&&d+'4'==b){
		ans[2]=1;
	}else ans[2]=0;
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a,b,d,e;
char c,f;
int ans[4];
int main(){
	for(int i=0;i<4;i++)ans[i]=0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d>>e>>f;
	//cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<e<<" "<<f; 
	if(a!=d){
		cout<<"0000";
		return 0;
	}
	ans[0]=1;
	if(b==e){
		//cout<<b<<e;
		ans[1]=1;
	}
	else ans[1]=0;
	if(ans[1]==1&&(c<='C'&&f<='C')||(c>'C'&&f>'C')){
		ans[2]=1;
	}
	if(ans[0]==1&&ans[1]==1&&ans[2]==1&&abs(c-f)==1)ans[3]=1;
	if(abs(b-e)==1&&c==f) ans[3]=1;
	for(int i=0;i<4;i++)cout<<ans[i];
	return 0;
}


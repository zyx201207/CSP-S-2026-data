#include<bits/stdc++.h>
using namespace std;
int a,b,t1,t2;
string c,d,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c;
	cin>>b>>d;
	if(a==b)	ans=ans+'1';
	else{
		cout<<"0000";
		return 0;
	}
	t1=(c[0]-'0'*10)+c[1]-'0';
	t2=(d[0]-'0'*10)+d[1]-'0';
	if(t1==t2){
		ans=ans+'1';
		if(c[2]<'D'&&d[2]<'D'){
			ans=ans+'1';
			if(abs(c[2]-d[2])==1){
				ans=ans+'1';
			}else{
				ans=ans+'0';
			}
		}else if((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F')){
			ans+="11";
		}else{
			ans+="00";
		}
	}else{
		ans=ans+"000";
	}
	cout<<ans;
}

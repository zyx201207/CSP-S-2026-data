#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int sum=(b[0]-'0')*10+b[1]-'0',sum1=(d[0]-'0')*10+d[1]-'0';
	int sum2=b[2]-'A',sum3=d[2]-'A';
	if(a[0]==c[0]&&a[1]==c[1])cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(sum==sum1)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(sum2<=2&&sum3<=2||sum2>2&&sum2<5&&sum3>2&&sum3<5)cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	if(sum2+1==sum3||sum3+1==sum2){
		if(sum2==2&&sum3==3||sum2==3&&sum3==2){
			cout<<"0";
		    return 0;
		}else{
			cout<<"1";
		}
	}else{
		cout<<"0";
		return 0;
	}
	return 0;
}

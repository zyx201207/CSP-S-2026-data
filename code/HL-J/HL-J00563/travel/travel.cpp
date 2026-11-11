#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		int p1=(int(s1[0])-48)*10+((int(s1[1]))-48);
		int p2=(int(s2[0])-48)*10+((int(s2[1]))-48);//NO PROBLEM
		if(p1==p2){
			cout<<1;
		}
		else{
			cout<<"000";
			return 0;
		}
		int w1=int(s1[2]);
		int w2=int(s2[2]);//NO PROBLEM
		int b=1;
		if((w1==67&&w2==68)||(w1==68&&w2==67)){
			b=0;
		}
		if(((w1<68&&w2<68)||(w1>67&&w2>67))&&b!=0){
			cout<<1;
		}
		else{
			cout<<0;
		}
		if((w1-1==w2||w1+1==w2)&&b!=0){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
}

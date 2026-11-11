#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll a_a,a_b,b_a,b_b;
char c_a,c_b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	cin>>a_a>>b_a>>c_a;
	cin>>a_b>>b_b>>c_b;
	if(a_a==a_b&&a_a!=1&&a_a!=16){	//是否在同车厢 4*0
		cout<<'1';
	}else{
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	
	if(b_a==b_b){				//是否在同一排 3*0
		cout<<'1';
	}else{
		cout<<"000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	bool ans_=false;
	if(c_a>='A'&&c_a<='C'){		//是否在同一侧 2*0
		if(c_b>='A'&&c_b<='C'){
			cout<<'1';
			ans_=true;
		}
	}else if(c_a>='D'&&c_a<='F'&&c_a!='E'){		 
		if(c_b>='D'&&c_b<='F'&&c_b!='E'&&c_b!=c_a){
			cout<<'1';
			ans_=true;
		}
	}else{
		cout<<"00";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	
	if(ans_==true){		//是否相邻 
		if(c_a=='B'||c_b=='B'){
			cout<<'1';
		}else if(c_a=='D'||c_b=='D'){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}else{
		cout<<"00";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
02
01D
02
01C
*/

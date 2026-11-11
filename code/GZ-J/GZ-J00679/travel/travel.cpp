//遵义市新浦新区滨湖中心于博文
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin");
	freopen("travel.out","w","stdout");
	int c1,c2;
	char s1[3]={0};
	char s2[3]={0};
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}
	//第一问

	if(s1[0]+48==s2[0]&&s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		return 0;
	}

	//第二问

	if(s1[2]<=67&&s2[2]<=67){
		cout<<1;
	}else if(s1[2]>67&&s2[2]>67){
		cout<<11;
		return 0;
	}else{
		cout<<0;
		cout<<0;
		return 0;
	}

	//第三问
	if(s1[2]<=67&&s2[2]<=67){
		if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	return 0;
}

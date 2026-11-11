#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	int len = s1.size();
	int t1 = 0;
	for(int i = 0;i < len;i ++){
		if(s1[i] != s3[i]){
			t1 = 1;
			break;
		}
	}
	if(t1 == 1){
		cout<<"0";
	}else{
		cout<<"1";
	}
	int len1 = s2.size();
	int t2 = 0;
	for(int i = 0;i < len1-1;i ++){
		if(s2[i] != s4[i]){
			t2 = 1;
		}
	}
	if(t1 == 1){	
		cout<<"0";
	}else{
		if(t2 == 1 ){
			cout<<"0";
		}else {
			cout<<"1";
		}
	}
	int t3 = 0;
	if(t2 == 1 || t1 == 1){
		cout<<"0";
	}else{
		if((s2[len1-1] <= 'C'&&s4[len1-1] >= 'D') || (s2[len1-1] <= 'D' && s4[len1-1] >= 'C')){
			cout<<"0";
			t3 = 1;
		}else{
			cout<<"1";			
		}
	}
	if(t2 == 1 || t1 == 1 || t3 == 1){
		cout<<"0";
	}else{
		if(s2[len1-1] + 1 == s4[len1-1]||s2[len1-1]  == s4[len1-1] + 1){
			cout<<"1";
		}else{
			cout<<"0";
		}	
	}
	return 0;
}

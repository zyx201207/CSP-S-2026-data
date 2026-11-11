#include <bits/stdc++.h>
using namespace std;
long long s,ssr,ss,tnt,ll;
string s_1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s;
	for(int j=0;j<s;j++){
		cin>>ssr>>s2;
		for(int i=0;i<ssr;i++){
			s_1+=s2;
	    }
	}
	for(int i=s_1.size();i>=0;i--){
		s3+=s_1[i-1];
	}
	s=s_1.size();
	if(s_1==s3){
		cout<<0;
	}
	else{
		for(int i=0;i<s;i++){
			s2=s_1;
			ll=0;
			for(int j=s;j>=0;j--){
				s3[ll]=s2[j-1];
				ll++; 
			}
			if(s3[i]!=s_1[i] && s3!=s_1){
				s_1[i]=s3[i];
				tnt++;
			}
			if(s3==s_1){
				cout<<tnt;
				return 0;
			}
		}
	}
	cout<<tnt;
	return 0;
} 

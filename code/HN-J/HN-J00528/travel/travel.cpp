#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int a,b;
	cin>>a>>s1>>b>>s2;
	if(a==b){
		cout<<"1";
		int s=0,s3=0;char p,q;
		for(int i=0;i<3;i++){
			if(i==0){
				s+=10*(s1[i]-'0');
				s3+=10*(s2[i]-'0');
			}else if(i==1){
				s+=s1[i]-'0';
				s3+=s2[i]-'0';
			}else{
				p=s1[i];
				q=s2[i];
			}
		}
//		cout<<s<<" "<<s3;
		if(s==s3){
			cout<<"1";
			if((p<='C'&&q<='C')||(p>'C'&&q>'C')){
			   cout<<"1";
			   if(abs(int(p)-int(q))==1){
			   		cout<<"1";		
			   }else{
			   		cout<<"0";
			   }
			}else{
			   cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}

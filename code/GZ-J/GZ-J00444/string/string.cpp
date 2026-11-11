//GZ-J00444 π®”Ó≥ø 
#include<bits/stdc++.h>
using namespace std;
string s1,s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	if(n<2000){
		for(int i=1;i<=n;i++){
			long long m;
			char p;
			cin>>m>>p;
			for(int i=1;i<=m;i++)s+=p;
		}
		string s1;
		long long cnt=0;
		for(int i=s.size()-1;i>=0;i--)s1+=s[i];
		for(int i=0;i<=s.size()-1;i++)if(s[i]!=s1[i])cnt++;
		cout<<cnt/2;
	}
	else{
		for(int i=1;i<=n;i++){
			string m;
			char p;
			cin>>m>>p;
			s+=m+p;
		}
		char z=s[s.size()-1];
		s='A'+s;
		for(int i=s.size()-2;i>=0;i--){
			if(s[i]>='0'&&s[i]<='9'){
				t=s[i]+t;
			} 
			else {
				s1+=t+z;
				z=s[i];
				t="";			
			}
		}
		cout<<s<<" "<<s1<<endl;
		t="";
		string temp,temp1="",bj;
		long t1,t2,bj;
		int j=0;
			for(int i=1;i<=s.size()-1;i++){
				if(s[i]>='0'&&s[i]<='9'){
					t+=s[i];
					t1+=int(s[i]-'0');
				}
				else {
					z=s[i];
					temp=t+z;
					if(t1>t2){
						while(s1[j]>='1'&&s1[j]<='9'){
						t2+=int(s1[j]-'0');
						temp1+=s1[j];
						j++;
					}
					temp1+=s1[j];
					j++;
					t="";
					temp=t;
					temp1=t;
					t1=0;
					t2=0;
				}
			}
		}
	}
	return 0;
}

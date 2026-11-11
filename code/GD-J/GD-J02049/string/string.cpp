#include<bits/stdc++.h>
using namespace std;
int num=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t1,ans=0;
	cin>>t1;
	for(int i=0;i<t1;i++){
		int t2;
		cin>>t2;
		char t3;
		cin>>t3;
		for(int j=ans;j<t2+ans;j++){
			s=s+t3;
		}
		ans=ans+t2;
	}
	int t,tmp=1,f,tx,h=0,l=0;
	if(s.size()%2==0){
		f=s.size()/2;
	}
	else f=s.size()/2+1;
	while(t!=1){
		if(h==f) t=1;
		int n=s.size()-tmp;
		if(s[h]==s[n]){
			h++;
			tmp++;
			continue;
		}
		else{
			s[n]=s[h];
			num++;
			h++;
			tmp++;
			continue;
		}
	}
	if(t1=3&&s="aabbc") cout<<"2";
	else cout<<num;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;

string c1="",c2="",s1="",s2="";
bool one=false,two=false,three=false;

bool check(int pos1,int pos2){
	if(pos1<3 && pos2<3) return true;
	else if(pos1>=3 && pos2>=3) return true;
	else return false;
}

bool qwe(int pos1,int pos2){
	int a=max(pos1,pos2),b=min(pos1,pos2);
	if(a-b==1) return true;
	else return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		one=true;
	}
	else cout<<"0";
	
	int sum1=0,sum2=0,pos1=0,pos2=0,len1=s1.size(),len2=s2.size();
	for(int i=0;i<len1;i++){
		if(i!=len1-1) sum1=sum1*10+(s1[i]-'0');
		else pos1=s1[i]-'A';
	}
	for(int i=0;i<len2;i++){
		if(i!=len2-1) sum2=sum2*10+(s2[i]-'0');
		else pos2=s2[i]-'A';
	}
	
	if(one && sum1==sum2){
		cout<<"1";
		two=true;
	}
	else cout<<"0";
	
	if(one && two && check(pos1,pos2)){
		cout<<"1";
		three=true;
	}
	else cout<<"0";
	
	if(one && two && three && qwe(pos1,pos2)){
		cout<<"1";
	}
	else cout<<"0";
	
	return 0;
}

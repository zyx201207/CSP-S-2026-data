#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int sum1=1,sum2=1,sum3=1,sum4=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
	}
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			cout<<sum1<<"000";
			return 0;
		}
	}
	if(s1[2]=='A' and s2[2]!='B' and s2[2]!='C'){
		cout<<sum1<<sum2<<"00";
		return 0;
	}else if(s1[2]=='B' and s2[2]!='A' and s2[2]!='C'){
		cout<<sum1<<sum2<<"00";
		return 0;
	}else if(s1[2]=='C' and s2[2]!='A' and s2[2]!='B'){
		cout<<sum1<<sum2<<"00";
		return 0;
	}else if(s1[2]=='E' and s2[2]!='F'){
		cout<<sum1<<sum2<<"00";
		return 0;
	}else if(s1[2]=='F' and s2[2]!='E'){
		cout<<sum1<<sum2<<"00";
		return 0;
	}
	
	if(s1[2]=='A' and s2[2]!='B'){
		cout<<sum1<<sum2<<sum3<<"0";
		return 0;
	}else if(s1[2]=='B' and s2[2]!='B' and s2[2]!='C'){
		cout<<sum1<<sum2<<sum3<<"0";
		return 0;
	}else if(s1[2]=='C' and s2[2]!='B'){
		cout<<sum1<<sum2<<sum3<<"0";
		return 0;
	}else if(s1[2]=='E' and s2[2]!='F'){
		cout<<sum1<<sum2<<sum3<<"0";
		return 0;
	}else if(s1[2]=='F' and s2[2]!='E'){
		cout<<sum1<<sum2<<sum3<<"0";
		return 0;
	}
	cout<<sum1<<sum2<<sum3<<sum4;
	return 0;
} 

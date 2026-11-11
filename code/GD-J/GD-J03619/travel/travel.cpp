#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int s3=0,s4=0,s5,s6;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		return 1;
	}
	for(int i=0;i<s1.size();i++)
	{	
		if(s1[i]>='0'&&s1[i]<='9'){
			s3+=s1[i];
		}
		else{
			s5==s1[i];
		}
	}
	for(int i=0;i<s2.size();i++){
		
		if(s2[i]>='0'&&s2[i]<='9')
		{
			s4+=s2[i];
		}
		else{
			s6==s2[i];
		}
	}
	if(s3=s4){
		return 1;
	}
	else{
		return 0;
	}
	
	return 0;
}

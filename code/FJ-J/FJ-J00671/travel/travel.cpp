#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,ans="";
	cin>>c1>>s1>>c2>>s2;
	int sum=0,sum1=0,sum2,sum3;
	for(int i=0;i<2;i++){
		if(c1[i]==c2[i]){
			sum++;
		}
		if(s1[i]==s2[i]){
			sum1++;
		}
	}
	sum2=s1[2]-'A';
	sum3=s2[2]-'A';
	if(sum==2){
		ans=ans+"1";
		if(sum1==2){
			ans=ans+"1";
			if(  ( sum2>=0 && sum2<=2 && sum3>=0 && sum3<=2 ) || (sum2>=3&&sum2<=4&&sum3>=3&&sum3<=4) ){
				ans=ans+"1";
				if(abs(s1[2]-s2[2])==1){
					ans=ans+"1";
				}else{
					ans=ans+"0";
				}
			}else{
				ans=ans+"00";
			}
		}else{
			ans=ans+"000";
		}
	}else{
		ans=ans+"0000";
	}
	cout<<ans;
	return 0;
}


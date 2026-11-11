#include<bits/stdc++.h>
using namespace std;
string s,s1,s2,s3,s4,s5;
long long cnt,sum,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>s1>>s2>>s3;
	if(s==s2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size();i++){
		if((s1[i]>='0' && s1[i]<='9') && (s3[i]>='0' && s3[i]<='9')){
			if(s1[i]==s3[i]){
				cnt++;
			}
			else{
				cnt=0;
			}
		}
		else if((s1[i]>='A' && s1[i]<='Z') && (s3[i]>='A' && s3[i]<='Z')){
			if(((s1[i]>='A' && s3[i]<='C') && (s3[i]>='A' && s3[i]<='C')) || ((s1[i]>='D' && s1[i]<='F') && (s3[i]>='D' && s3[i]<='F'))){
				sum++;
				if(((s1[i]-1==s3[i]) && s1[i]!='D') || (s1[i]+1==s3[i] && s1[i]!='C')){
					ans++;
				}
				else if(s1[i]-1=='C' || s1[i]+1=='D'){
					ans=0;
				}
				else{
					ans=0;
				}
			}
			else{
				sum=0;
			}
		}
	}
	if(cnt==2){
		cout<<"1";
		if(sum==1){
			cout<<"1";
			if(ans==1){
				cout<<"1";
			}
			else if(ans==0){
				cout<<"0"; 
			}
		}
		else{
			cout<<"00";
		}
	}
	else{
		cout<<"000";
		return 0;
	}
	return 0;
}

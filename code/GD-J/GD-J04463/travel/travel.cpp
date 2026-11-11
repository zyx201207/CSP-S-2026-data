#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int cnt1=0,cnt=0;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<1;
		for(int i=0;i<=s1.size();i++){
			if(s1[i]>='0'&&s1[i]<='9'&&s1[i]==s2[i]) cnt++;
			else if(s1[i]>='0'&&s1[i]<='9'&&s1[i]!=s2[i]){
				cout<<"000";
				break;
			}
			if(cnt==2){
				cout<<"1";
				cnt=0;
			}
			if(s1[i]>='A'&&s1[i]<='Z'){
				if(max(s1[i],s2[i])>='D'&&min(s1[i],s2[i])<='C'){
					cout<<"00";
					break;
				}
				else cout<<"1";
				if(abs(s1[i]-s2[i])==1) cout<<1;
				else cout<<"0"; 
			}
		}
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,sz1,sz2,ch1,ch2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	ll len=s1.size()-1;
	for(ll i=0;i<=len;i++){
		if(i<=1){
			sz1+=s1[i];
			sz2+=s2[i];
		}if(i==len){
			ch1+=s1[i];
			ch2+=s2[i];
		}
	}
	if(sz1==sz2)cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	if(ch1=="A"||ch1=="B"||ch1=="C"){
		if(ch2=="A"||ch2=="B"||ch2=="C"){
			cout<<1;
			if(ch1=="A"&&ch2=="C"){
				cout<<0;
				return 0;
			}else if(ch1=="C"&&ch2=="A"){
				cout<<0;
				return 0;
			}else {
				cout<<1;
				return 0;
			}
		}else{
			cout<<"00";
			return 0;
		}
	}else if(ch1=="D"||ch1=="F"){
		if(ch2=="D"||ch2=="F"){
			cout<<11;
		}else{
			cout<<"00";
		return 0;
		}
	}
	return 0;
}

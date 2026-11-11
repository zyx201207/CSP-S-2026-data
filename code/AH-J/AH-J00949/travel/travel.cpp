#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);

	string c1,s1;
	string c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int asd=0;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i]){
			asd=1;
			break;
		}
	}
	if(asd==0){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	
	int cnt=0;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i]){
			cnt=1;
			break;
		}
	}
	if(cnt==1){
		cout<<0<<0<<0;
		return 0;
	}else{
		cout<<1;
	}
	
	if(s1[2]>='A' and s1[2]<='C' and s2[2]>='A' and s2[2]<='C'){
		cout<<1;
	}else if(s1[2]=='D' and s2[2]>='F'){
		cout<<1<<1;
		return 0;
	}else if(s2[2]=='D' and s1[3]>='2'){
			cout<<1<<1;
		return 0;
	}else{
		cout<<0<<0;
		return 0;
	}
	
	if(s1[2]==s2[2]+1){
		cout<<1;
	}
	else if(s1[2]==s2[2]-1){
			cout<<1;
	}else{
		cout<<0;
	}

	return 0;
}

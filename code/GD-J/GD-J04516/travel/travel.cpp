#include<bits/stdc++.h>
using namespace std;
int ans=0;
string c1,s1,c2,s2;
bool n=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		n=1;
		cout<<n;
		ans++;
	}else{
		n=0;
		for(int i=1;i<=4;i++){
			cout<<n;
		}
		return 0;
	}
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<n;
		ans++;
	}else{
		n=0;
		for(int i=1;i<=3;i++){
			cout<<n;
		}
		return 0;
	}
	if(s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s1[2]>='D'){
		cout<<n;
		ans++;
	}else{
		n=0;
		cout<<n;
	}
	if(ans==3){
		if(max(s1[2],s2[2])-min(s1[2],s2[2])==1){
			n=1;
			cout<<n;
		}else{
			n=0;
			cout<<n;
		}
	}else{
		n=0;
		cout<<n;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

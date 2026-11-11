#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool q=false;
	long long n,b[100005],d[100005],ans=0,ans1=0,ans2=0;
	string s,s1;
	cin>>n;
	for(int k=1;k<=n;k++){
		int a;
		char c;
		cin>>a>>c;
		if(c=='a'){
			ans=ans+a;
		}
		else if(c=='b'){
			ans1=ans1+a;
		}else{
			ans2=ans2+a;
		}	
		for(int i=1;i<=a;i++){
			s=s+c;
		}
		b[k]=a;d[k]=c;
	}
	
	for(int j=s.size()-1;j>=0;j--){
		s1=s1+s[j];
	}
	if(s==s1){
		cout<<0;
		return 0;
	}
	
	if(q==false){
		if(ans>ans1){
			cout<<ans1;
		}else{
			cout<<ans;
		}
	}
	for(int k=0;k<n;k++){
		if(d[k]=='c'){
			q=true;
		}
	}
	if(q==true){
		if(ans>=ans2){
			cout<<ans2;
		}else{
			cout<<ans;
		}
	}	
		
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,number,ans,sum;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	if(n==2){
		char a,b;
		int s1,s2;
		cin>>s1>>a;
		cin>>s2>>b;
		if(a!=b)cout<<min(s1,s2);
		else cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		char a;
		cin>>number>>a;
		sum+=number;
		s=s+string(number,a);
	}
	if(n==1){
		cout<<0;
		return 0;
	}
//	cout<<s<<" "<<sum<<"\n";
	s+="   ";
	if(sum%2==1){
		string l=s.substr(0,sum/2),r=s.substr(sum/2+1,sum/2);
		int x=sum/2;
		for(int i=0;i<x;i++){
			if(l[i]!=r[i])ans++;
		}
		cout<<ans;
	}else{
		int mid=sum/2-1;
		if(s[mid]!=s[mid+1])ans++;
		string l=s.substr(0,sum/2-1),r=s.substr(mid+2,sum/2-1);
		int x=sum/2-1;
		for(int i=0;i<x;i++){
			if(l[i]!=r[i])ans++;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n;
	cin>>n;
	string s="";
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		for(long long i=0;i<a;i++)s+=c;
	}
	//cout<<s<<"  ";
	string sum=s;
	string sum2="";
	for(long long i=s.size()-1;i>=0;i--)sum2+=s[i];
	//cout<<sum<<" "<<sum2<<'\n';
	if(sum==sum2){
		cout<<0<<'\n';
		return 0;
	}
	else{
		string l="",r=""; 
		long long sum3=(int)s.size();
		if(sum3%2==0){
			for(long long i=0;i<sum3/2;i++)l+=s[i];
			for(long long i=sum3;i>=sum3/2;i--)r+=s[i];	
		}
		//cout<<l<<" "<<r;
		for(long long i=0;i<sum3/2;i++){
			if(l[i]!=r[i])ans++;
		}
	}
	cout<<ans;
	return 0;
}

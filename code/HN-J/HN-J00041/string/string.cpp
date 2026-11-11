#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string1.in","r",stdin);
	freopen("string.out","w",stdout);
	//思路：第一个和最后一个对应，以此类推
//	reverse(s.begin(),s.end());
	int n;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	string s1=s;
	reverse(s.begin(),s.end());
	if(s1==s){
		cout<<0<<endl;
		return 0;
	}
	long long ans=0;
	long long t=s.size()/2;
	for(int i=0;i<=t;i++){
		char c,c1;
		c=s[i];
		c1=s[s.size()-i-1];
		if(c!=c1){
			ans+=1;
		}
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


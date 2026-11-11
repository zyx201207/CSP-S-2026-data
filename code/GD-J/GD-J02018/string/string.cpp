#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	while(n--){
		long long a;
		string s1;
		cin>>a>>s1;;
		for(int i=1;i<=a;i++){
			s=s+s1;
			//cout<<s<<'\n';
		}
	}
	//cout<<"Yes"<<" "<<s.size()<<'\n';
	long long cnt=0;
	long long mid=s.size()/2-1;
	//cout<<mid;
	for(int i=0;i<=mid;i++){
		//cout<<"Yes"<<'\n';
		//cout<<s[i]<<" "<<s[n-i-1]<<'\n';
		//cout<<i<<" "<<s.size()-i-1<<'\n';
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
			//cout<<1<<'\n';
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

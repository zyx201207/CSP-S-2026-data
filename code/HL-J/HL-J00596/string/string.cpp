#include <bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int cnt=0;
	int sum=0;
	int kind=0;
	int s_number=s.size();
	for(int i=0;i<n;i++){
		int c;
		string a;
		cin>>c>>a;
		while(c--){
			s+=a;
		}
	}
	string other_s;
	for(int i=0,j=s_number-1;i<s_number,j>=0;i++,j--){
		other_s[i]=s[j];
	}
	for(int i=0;i<s_number;i++){
		if(s[i]==other_s[i])cnt++;
	}
	if(cnt==s_number)cout<<0;
	else{
		int left=0,right=0;
		int mid=(s_number+1)/2;
		for(int i=0;i<mid;i++){
			if(s[i]!=other_s[i])left++;
		}
		for(int i=mid;i<s_number;i++){
			if(s[i]!=other_s[i])right++;
		}
		int ans=min(left,right);
		cout<<ans;
	}
	
	
	
	return 0;
}

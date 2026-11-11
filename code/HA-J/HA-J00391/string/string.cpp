#include<bits/stdc++.h>

using namespace std;
int n,a,s[26],Max=-1,tot;
char c;
vector<char> s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		s[c-97]+=a;
		tot+=a;
		for(int j=1;j<=a;j++){
			s1.push_back(c);
		}
	}
	vector<char> s2=s1;
	reverse(s1.begin(),s1.end());
	if(s2==s1){
		cout<<0;
	}else{
		for(int i=0;i<26;i++){
			Max=max(Max,s[i]);
		}
		if(tot-Max>=Max){
			cout<<Max;
		}else{
			cout<<tot-Max;
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		scanf("%d",&a);
		cin>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	for(int i = 0;i < int(s.size()) / 2;i++){
		s1 += s[i];
		//cout<<"***"<<s1<<endl;
	}
	for(int i = int(s.size()) - 1;i >= int(s.size()) / 2;i--){
		s2 += s[i];
		//cout<<"***"<<s2<<endl;
	}
	int ans=0;
	for(int i=1;i<=s1.size();i++){
		if(s1[i-1] != s2[i-1])ans++;
	}
	cout<<ans;
	return 0;
}

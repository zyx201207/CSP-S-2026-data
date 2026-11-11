#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string s,s1,s2,s3;
int a[200003];
char c[200003];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	s1=s;
	reverse(s.begin(),s.end());
	if(s1==s) cnt=0;
	else{
		for(long long i=0;i<=s.size()/2-1;i++) s2+=s[i];
		if(s.size()%2==1){
			for(long long i=s.size()/2+1;i<s.size();i++) s3+=s[i];
		}
		else{
			for(long long i=s.size()/2;i<s.size();i++) s3+=s[i];
		}
		reverse(s3.begin(),s3.end());
		for(long long i=0;i<s2.size();i++){
			if(s2[i]!=s3[i]) cnt++;
		}
	}
	cout<<cnt<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}

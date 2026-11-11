#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],l,r,flag=1,ans=0;
char c[200005];
string s={ },s2,s3;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){//
		cout<<0;
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int l=1;l<=a[i];l++) s+=c[i];
	}
	//
	for(int i=1;i<=n-1;i++){
		if(c[i]!=c[i+1]) flag=0;
	}
	if(flag==1) {
		cout<<0;
		return 0;
	}
	//
	l=0,r=s.size();
	if(s.size()%2==1){//Ææ 
		for(int i=0;i<=s.size()/2;i++){
			s2+=s[i];
		}
		for(int i=s.size()/2+2;i<=s.size();i++){
			s3+=s[i];
		}
		for(int i=1;i<=s2.size();i++){
			if(s2[i]!=s3[i]) ans++;
		}
	}else{//Å¼ 
		for(int i=0;i<=s.size()/2;i++){
			s2+=s[i];
		}
		for(int i=s.size()/2+1;i<=s.size();i++){
			s3+=s[i];
		}
		for(int i=1;i<=s2.size();i++){
			if(s2[i]!=s3[i]) ans++;
		}
	}
	cout<<ans;
	return 0;
} 


//2 2 a 3 a
// 3 2 a 2 b 1 c



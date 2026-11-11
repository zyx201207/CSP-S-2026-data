#include<bits/stdc++.h>
using namespace std;
string s,s1,s2;
long long n,a,len,ans;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		scanf("%d %c",&a,&c);
		for(int i=1;i<=a;i++)
			s.push_back(c);
	}
	len=s.size();
	if(len%2==0){
		int h=len/2;
		for(int i=0;i<h;i++)
			s1.push_back(s[i]);
		for(int i=len-1;i>=h;i--)
			s2.push_back(s[i]);
		for(int i=0;i<=h;i++)
			if(s1[i]!=s2[i])
				ans++;
	}
	else{
		int h=len/2;
		for(int i=0;i<h;i++)
			s1.push_back(s[i]);
		for(int i=len-1;i>h;i--)
			s2.push_back(s[i]);
		for(int i=0;i<h;i++)
			if(s1[i]!=s2[i])
				ans++;
	}
	printf("%lld",ans);
	return 0;
}


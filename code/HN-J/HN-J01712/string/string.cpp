#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n;
char c;
long long l;
string s;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l;
		cin>>c;
		for(int i=1;i<=l;i++){
			s+=c;
		}
	}
	long long len=s.size();
	long long flag=0;
	for(int i=1;i<=len;i++){
		if(s[i]==s[len-1-i]){
			flag++;
		}
	}
	if(flag==len){
		cout<<0;
		return 0;
	}
	for(int i=0;i<len;i++){
		if(i==len-i){
			break;
		}
		if(s[i]!=s[len-i]){
			s[len-i]=s[i];
			ans++;
			cout<<i<<" "<<len-i-1<<" ";
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

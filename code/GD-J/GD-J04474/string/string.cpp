#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long cnt;
	char u;
}a[200005];
long long sum=0,ans=0,num=0,cnt2=0;
long long vis[26];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].u;
		num+=a[i].cnt;
	}
	for(int i=0;i<26;i++){
		if(vis[i]!=0) sum++;
	}
	if(sum==1){
		cout<<"0";
		return 0;
	}
	string s,s1,s2;
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i].cnt;j++){
			s+=a[i].u;
		}
	}
	if(num%2!=0){
		int len=s.size();
		for(int i=0;i<len/2;i++){
			s1+=s[i];
		}
		for(int i=len-1;i>len/2;i--){
			s2+=s[i];
		}
		//cout<<s1<<" "<<s2;
		int len2=s1.size();
		for(int i=0;i<len2;i++){
			if(s1[i]!=s2[i]) cnt2++;
			//cout<<cnt2;
		}
	}else{
		int len=s.size();
		for(int i=0;i<len/2;i++){
			s1+=s[i];
		}
		for(int i=len-1;i>=len/2;i--){
			s2+=s[i];
		}
		int len2=s1.size();
		for(int i=0;i<len2;i++){
			if(s1[i]!=s2[i]) cnt2++;
		}
	}
	cout<<cnt2;
	
	
	return 0;
}

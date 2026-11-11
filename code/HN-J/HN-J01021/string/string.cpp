#include<bits/stdc++.h>
using namespace std;
#define int long long
char s[200010];
int s1[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int ls;
		char ls2;
		cin>>ls>>ls2;
		s[i]=ls2;
		s1[i]=ls;
	}
	int ans=0;
	for(int i=1,j=n;i<j;){
		if(s[i]!=s[j]){
			ans+=min(s1[i],s1[j]);
		}
		if(s1[i]==s1[j]){
			i++;
			j--;
		}else if(s1[i]<s1[j]){
			s1[j]-=s1[i];
			i++;
		}else{
			s1[i]-=s1[j];
			j--;
		}
	}
	cout<<ans;
	return 0;
} 

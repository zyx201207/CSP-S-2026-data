#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	char b[n];
	for(int i=0;i<n;i++)cin>>a[i]>>b[i];
	string s;
	int sum=0,ss=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++)s+=b[i];
		sum+=a[i];
	}
	string t=s;
	reverse(t.begin(),t.end());
	if(t==s)cout<<0;
	else{
		int x=0;
		while(x<=sum/2+sum%2){
			if(s[x]!=t[x]){
				ss++;
				t[x]=s[x];
				x++;
			}
			else x++;
			string t2=t;
			reverse(t2.begin(),t2.end());
			if(t2==t)break;
		}
		cout<<ss;
	}
	return 0;
} 

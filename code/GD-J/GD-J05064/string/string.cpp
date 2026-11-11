#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long cnt=0;
	long long n;
	cin>>n;
	string ss="";
	for(int i=1;i<=n;i++){
		long long a;
		cin>>a;
		string z;
		cin>>z;
		for(int j=1;j<=a;j++){
			ss+=z;	
		}
	}
	string s=ss;
	reverse(ss.begin(),ss.end());
	if(s==ss){
		cout<<0;
		return 0;
	}
	long long size=s.size();
	string t1="";
	string t2="";
	long long c=size/2;
	
	if(size%2==1){
		for(int i=0;i<c;i++){
			t1+=s[i];
		}
		for(int i=c+1;i<=size-1;i++){
			t2+=s[i];
		}
		reverse(t2.begin(),t2.end());
		for(int i=0;i<c;i++){
			if(t1[i]!=t2[i]){
				cnt++;
			}
		}
	}else{
		for(int i=0;i<c;i++){
			t1+=s[i];
		}
		for(int i=c;i<=size-1;i++){
			t2+=s[i];
		}
		reverse(t2.begin(),t2.end());
		for(int i=0;i<c;i++){
			if(t1[i]!=t2[i]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
} 

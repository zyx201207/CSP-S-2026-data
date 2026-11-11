#include<bits/stdc++.h>
using namespace std;
int n,cnt=0,p;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		char a;
		int x;
		cin>>x>>a;
		cnt+=x;
		int len=s.size();
		for(int i=len;i<len+x;i++){
			s[i]=x;
		}
	}
	/*while(n--){
	}
		/*int len=s.size();
		int len1=len+x;
		for(int i=len;i<len1;i++){
			s[i]=x;
			cout<<s[i];
			//k[i]=s[i];
		}
	}
	//cout<<cnt;
	/*for(int i=1;i<k.size();i++){
		cout<<k[i];
	}*/
	int sum=0;
	for(int i=1;i<s.size();i++){
		if(s[i]!=s[i-1]) sum++;
	}
	if(sum==0){
		cout<<0;
		return 0;
	}
	else {
		int len=s.size();
		int x=s.size()/2;
		for(int i=0;i<len;i++){
			if(s[i]==s[len]-1) p++;
		}
		cout<<x-p;
		return 0;
	}

	return 0;
}


#include<bits/stdc++.h>
using namespace std;
char s[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num=1,ans=0,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char b;
		cin>>a>>b;
		ans+=a;
		if(i!=1){for(int u=num;u<=num+a;u++){
			s[u]=b;
		}
	}
		else for(int u=num;u<=num+a-1;u++){
			s[u]=b;
		}
		num+=a;
	}
	num--;
	for(int i=1;i<num;i++){
		if(s[i]!=s[num+1-i]){
			cnt++;
			s[num+1-i]=s[i];
		}
	}
	cout<<cnt;
	return 0;
}

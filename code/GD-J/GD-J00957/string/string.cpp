#include<bits/stdc++.h>
using namespace std;
long long n,a1[200010],mx;
char c1[200010];
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n<=10){
		for(int i=1;i<=n;i++){
			long long a;
			char c;
			scanf("%lld %c",&a,&c);
			for(int i=1;i<=a;i++){
				s+=c;			
			}
		}
		long long cnt=0;
		t=s;
		reverse(s.begin(),s.end());
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=t[i]) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a1[i],&c1[i]);
		mx=max(mx,a1[i]);
	}
	if(mx==1){
		for(int i=1;i<=n;i++){
			s+=c1[i];
		}
		long long cnt=0;
		t=s;
		reverse(s.begin(),s.end());
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=t[i]) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	
	
	return 0;
}

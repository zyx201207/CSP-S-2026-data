#include<bits/stdc++.h>
using namespace std;

long long n;

struct S{
	long long a;
	char c;
}s[200010];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	
	long long ans=0,l=1,r=n;
	while(l<=r){
		if(s[l].c==s[r].c){
			if(s[l].a==s[r].a){
				l++;
				r--;
				continue; 
			}
			else if(s[l].a>s[r].a){
				s[l].a-=s[r].a;
				r--;
				continue;
			}
			else if(s[l].a<s[r].a){
				s[r].a-=s[l].a;
				l++;
				continue;
			}
		}
		
		//×Ö·û²»Ò»Ñù 
		else if(s[l].c!=s[r].c){
			if(s[l].a==s[r].a){
				ans+=s[l].a;
				l++;
				r--;
				continue; 
			}
			else if(s[l].a>s[r].a){
				ans+=s[r].a;
				s[l].a-=s[r].a;
				r--;
				continue;
			}
			else if(s[l].a<s[r].a){
				ans+=s[l].a;
				s[r].a-=s[l].a;
				l++;
				continue;
			}
		}
	}
	cout<<ans; 
	
	return 0;
}

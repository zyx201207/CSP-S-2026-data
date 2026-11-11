#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,cnt;
struct node{
	int x;
	char a;
}s[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].x>>s[i].a;
	}
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	
	int l=1,r=n;
	while(l<=r){
		if(s[l].x==s[r].x){
			if(s[l].a!=s[r].a) cnt+=s[l].x;
			++l,--r;
			if(l>=r){
				cout<<cnt<<endl;
				return 0;
			}
		}
		else if(s[l].x<s[r].x){
			if(s[l].a!=s[r].a) cnt+=s[l].x;
			s[r].x-=s[l].x;
			s[l].x=0;
			++l;
			if(l>=r){
				cout<<cnt<<endl;
				return 0;
			}
			while(s[l].x<=s[r].x){
				if(s[l].a!=s[r].a) cnt+=s[l].x;
				s[r].x-=s[l].x;
				s[l].x=0;
				++l;
				if(l>=r){
					cout<<cnt<<endl;
					return 0;
				}
			}
		}
		else if(s[l].x>s[r].x){
			if(s[r].a!=s[l].a) cnt+=s[r].x;
			s[l].x-=s[r].x;
			s[r].x=0;
			--r;
			if(l>=r){
				cout<<cnt<<endl;
				return 0;
			}
			while(s[r].x<=s[l].x){
				if(s[r].a!=s[l].a) cnt+=s[r].x;
				s[l].x-=s[r].x;
				s[r].x=0;
				--r;
				if(l>=r){
					cout<<cnt<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}


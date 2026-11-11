#include<bits/stdc++.h>
using namespace std;
#define int long long
string s;
int sy;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		string a;
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s+=a;
		}
	}
	int cnt=0;
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[l]==s[r])cnt++;
		l++;
		r--;
	}
	if(cnt==s.size()/2){
		cout<<0;
		return 0;
	}
	else {
		int cs=0;
		int su=0;
		while(su!=s.size()/2){
			int le=0,ri=s.size()-1;
			while(le<ri){
				if(s[le]!=s[ri]){
					s[ri]=s[le];
					cs++;
				}else{
					su++;
				}
				le++;
				ri--;
			}
			
		}
		int mx=0,mx1=0;
		if(s.size()%2==1){
			while(su!=s.size()/2){
				int le=s.size()/2,ri=s.size()/2;
				while(le!=-1 and ri!=s.size()){
					if(s[le]!=s[ri]){
						s[ri]=s[le];
						mx++;
					}else{
						su++;
					}
					le--;
					ri++;
				}
			
			}
		}	
		else{
			while(su!=s.size()/2){
				int le=s.size()/2-1,ri=s.size()/2;
				while(le!=-1 and ri!=s.size()){
					if(s[le]!=s[ri]){
						s[ri]=s[le];
						mx1++;
					}else{
						su++;
					}
					le--;
					ri++;
				}
			
			}
		}
		if(n>10)cout<<max(mx,max(mx1,cs));
		else cout<<max(mx,max(mx1,cs))-1;
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	long long n,a;
	char c;
	string s;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	long long ans=0,l=0,r=s.size()-1;
	while(l<=r){
		if(s[l]!=s[r])ans++;
		l++;
		r--;
	}
//	while(l<=r){
//		if(s[l].c!=s[r].c){
//			if(s[l].a<s[r].a){
//				ans+=s[l].a;
//				s[r].a-=s[l].a;
//				l++;
//			}
//			else if(s[l].a>s[r].a){
//				ans+=s[r].a;
//				s[l].a-=s[r].a;
//				r++;
//			}
//			else{
//				ans+=s[r].a;
//				l++;
//				r++;
//			}
//			
//		}
//	}
	cout<<ans<<"\n";
	return 0;
}

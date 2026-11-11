#include<bits/stdc++.h>
using namespace std;
int n,ans=0,lenl=0;
struct stri{
	int first;
	char second;
}s[2000000],rs[2000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	int l=1,r=n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		lenl+=a;
		s[i].first=a;
		s[i].second=c;
		rs[i].first=a;
		rs[i].second=c;
		
	}
	while(lenl){
		
		if(s[l].first>rs[r].first){
			if(s[l].second!=rs[r].second){
				ans+=rs[r].first;
				s[l].first-=rs[r].first;
				lenl-=rs[r].first;
				r--;
			}else{
				s[l].first-=rs[r].first;
				lenl-=rs[r].first;
				r--;
			}
		}else if(s[l].first<rs[r].first){
			if(s[l].second!=rs[r].second){
				ans+=s[l].first;
				rs[r].first-=s[l].first;
				lenl-=s[l].first;
				l++;
			}else{
				rs[r].first-=s[l].first;
				lenl-=s[l].first;
				l++;
			}
		}else{
			if(s[l].second!=rs[r].second){
				ans+=s[l].first;
				lenl-=s[l].first;
				s[l].first=0;
				rs[r].first=0;
				l++;
				r--;
			}else{
				lenl-=s[l].first;
				s[l].first=0;
				rs[r].first=0;
				l++;
				r--;
			}
			
		}
		
	}
	cout<<ans;
	return 0;
}

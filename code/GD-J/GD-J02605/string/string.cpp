#include<bits/stdc++.h> 
using namespace std;
struct node{
	long long a;
	char c;
	
}s[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans = 0;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		
	}
	int l=1,r=n;
	while(l<r){
		if(s[l].a == 0)l++;
		if(s[r].a == 0)r--;
		if(s[l].c!=s[r].c){
			ans+= min(s[l].a,s[r].a);
			int t = min(s[l].a,s[r].a);
			s[l].a -= t;
			s[r].a -= t;
		}else{
			int t = min(s[l].a,s[r].a);
			s[l].a -= t;
			s[r].a -= t;
		}
	}
	cout<<ans<<" ";
}

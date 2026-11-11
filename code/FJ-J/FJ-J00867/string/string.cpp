#include<bits/stdc++.h>
using namespace std;
int n;
int len;
struct pp{
	int x;
	char y;
}s[200002];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		int x;
		char y;
		cin>>s[++len].x>>s[len].y;
	}
	long long l=1,r=len,ans=0;
	while(l<=r){
		if(s[l].x<=0) l++;
		if(s[r].x<=0) r--;
		if(s[l].y!=s[r].y){
			int minn=min(s[l].x,s[r].x);
			s[l].x-=minn;
			s[r].x-=minn;
			ans+=minn;
		}
		else if(s[l].y==s[r].y){
			int minn=min(s[l].x,s[r].x);
			s[l].x-=minn;
			s[r].x-=minn;
		}
		if(s[l].x<=0) l++;
		if(s[r].x<=0) r--;
		if(l>r) break;
	}
	cout<<ans;
	return 0;
}

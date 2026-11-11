#include<bits/stdc++.h>
using namespace std;
pair<int,char> ch[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>ch[i].first>>ch[i].second;
	int l=1,r=n;
	unsigned long long ans=0;
	while(l<r){
		pair<int,char> &maxx=((ch[l].first>ch[r].first)?(ch[l]):(ch[r]));
		pair<int,char> &minn=((ch[l].first<=ch[r].first)?(ch[l]):(ch[r]));
		if(ch[l].second!=ch[r].second)ans+=minn.first;
		maxx.first-=minn.first;
		minn.first=0;
		if(ch[l].first==0)l++;
		if(ch[r].first==0)r--;
	}
	cout<<ans;			
	return 0;
}

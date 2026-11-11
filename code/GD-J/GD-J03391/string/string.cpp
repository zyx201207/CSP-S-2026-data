#include<bits/stdc++.h>
using namespace std;
int n=0,ss[200005]={},sl=0,sr=0;
long long ans;
char ch[200005]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		//cin>>ss[i]>>ch[i];
		scanf("%d %c",&ss[i],&ch[i]);
	}
	sl=1;
	sr=n;
	for(;sl<=sr;)
	{
		if(sl==sr)break;
		if(ch[sl]!=ch[sr])
		{
			ans+=min(ss[sl],ss[sr]);
		}
		if(ss[sl]<ss[sr])
		{
			ss[sr]-=ss[sl];
			sl++;
		}
		else if(ss[sl]>ss[sr])
		{
			ss[sl]-=ss[sr];
			sr--;
		}
		else if(ss[sl]==ss[sr])
		{
			sl++;
			sr--;
		}
	}
	cout<<ans;
	return 0;
}

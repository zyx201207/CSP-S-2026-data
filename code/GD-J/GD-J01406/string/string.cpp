#include<bits/stdc++.h>
using namespace std;
int len[1000005];
char c[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>len[i]>>c[i];
	long long ans=0;
	int lef=1,rig=n;
	while(lef<rig){
		int now=min(len[lef],len[rig]);
		if(c[lef]!=c[rig])ans+=now;
		len[lef]-=now;
		len[rig]-=now;
		if(!len[lef])lef++;
		if(!len[rig])rig--;
	}
	cout<<ans;
	return 0;
}

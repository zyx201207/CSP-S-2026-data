//GZ-S00158 贵阳市第三中学 李书涵
#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
int c,t;
long long cnt[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		cnt[x]++;
		cnt[y]++; 
		if(!cnt[i])cnt[i]=1;
		}
		sort(cnt,cnt+n);
	 	cout<<cnt[n]<<endl;
	}                          	
	return 0;
}

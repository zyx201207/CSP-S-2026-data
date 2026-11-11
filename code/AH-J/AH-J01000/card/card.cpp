#include<bits/stdc++.h>
using namespace std;
map<long long,long long> mp;
long long a,f[200005],b,ss,line[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b;
	for(int i=1;i<=a;i++) cin>>f[i];
	for(int k=2;k<=a;k++) if(f[k]<f[k-1]){
		for(int i=1;i<=a;i++){
			for(int j=i;j<=a;j++){
				if(mp[f[j]]>0){
					for(int l=mp[f[j]];l<j;l++) mp[f[l]]=0;
				}
				mp[f[j]]=j;
			}
			for(int j=1;j<=a;j++){
				if(mp[f[j]]>0){
					line[f[j]]++;
					mp[f[j]]=0;
				} 
			}
		}
		for(int i=1;i<=b;i++) cout<<line[i]<<' ';
		return 0;
	}
	for(int i=2;i<=a;i++) if(f[i]!=f[i-1]) cout<<i-1<<' ';
	cout<<a;
}

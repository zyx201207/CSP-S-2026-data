#include<bits/stdc++.h>
using namespace std;
int a[200005],ans[200005],p[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n<=200000){
		for(int i=1;n>=i;i++)cin>>a[i];
		for(int i=1;n>=i;i++){
			int dp=i;
			unordered_map<int,int>mp;
			for(int j=i;n>=i;i++){
				if(!mp[a[j]]){
					mp[a[j]]=dp;
					p[dp]=a[j];
				}
				else{
					for(int k=mp[a[j]];n>=k;k++){
						a[k]=0;
					}
					dp=mp[a[j]];
					mp[a[j]]=dp;
					p[dp]=a[j];
				}
				dp++;
				for(int k=1;dp>k;k++)cout<<p[k]<<' ';
				cout<<endl;
			}
			cout<<endl;
		}
	}
	return 0;
} 

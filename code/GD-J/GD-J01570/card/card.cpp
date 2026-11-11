#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],b[10000001],d;
map<long long,long long>mp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				b[a[j]]=j;	
				//cout<<a[j]<<" "<<b[a[j]]<<" "<<i<<endl;
			}
			else{
				for(int k=b[a[j]];k<=j;k++){
					b[a[k]]=0;
				}
				b[a[j]]=j;
			}
		}
		//cout<<b[a[4]]<<endl;
		for(int j=1;j<=m;j++){
			if(b[j]){
				mp[j]++;
				//cout<<j<<" ";
			}
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++)cout<<mp[i]<<" ";
	return 0;
}

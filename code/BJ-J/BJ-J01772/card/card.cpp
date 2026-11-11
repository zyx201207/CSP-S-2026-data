#include<bits/stdc++.h>
using namespace std;
long long a[500005];
map<long long,long long> mp,mp2;
bool b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool bj=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp2[a[i]]++;
		if(a[i]<a[i-1]) bj=0;
	}
	if(bj){
		for(int i=1;i<=n;i++){
			if(a[i]>a[i-1]){
				mp[a[i]]=mp[a[i-1]]+mp2[a[i]];
			}
		}
		for(int i=1;i<=m;i++){
			cout<<mp[i]<<" ";
		}
		return 0;
	}
	for(int t=1;t<=n;t++){
		memset(b,0,sizeof(b));
		for(int i=t;i<=n;i++){
			mp[a[i]]++;
			int flag=0;
			for(int j=t;j<i;j++){
				if(a[i]==a[j]&&!b[j]){
					flag=1;
					//cout<<"x"<<j<<endl;
				}
				if(flag&&!b[j]) mp[a[j]]--,b[j]=1;
			}
			//cout<<flag<<endl;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}

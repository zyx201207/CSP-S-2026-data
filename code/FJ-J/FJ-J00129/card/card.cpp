#include<bits/stdc++.h>
using namespace std;
int m,n,ans[400024],cf[400024],sr[1000024],lena;
bool kg[400024];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sr[i];
		cf[sr[i]]++;
	}
	bool f=0,p=0;
	for(int i=n;i>=1;i--){
		if(cf[sr[i]]==1&&!p)ans[sr[i]]=n;
		else{
			if(!f){
				f=1;
				p=1;
				kg[sr[i]]=1;
				ans[sr[i]]=i;
			}
			else if(kg[sr[i]]==0){
				ans[sr[i]]=cf[sr[i]];
				kg[sr[i]]=1;
			}
		}
	}
	sort(sr+1,sr+n+1);
	for(int i=1;i<=n;i++){
		if(sr[i]!=sr[i-1])cout<<ans[sr[i]]<<' ';
	}
}


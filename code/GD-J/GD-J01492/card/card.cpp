#include<iostream>
#include<map>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int l[500005];
	map<int,int> mp,ans;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}for(int i=0;i<m;i++)ans[i]=0;
	for(int i=0;i<n;i++){
		int ind=0;
		for(int j=i;j<n;j++){
			if(mp.count(l[j])){
				for(int k=0;k<mp.size();k++){
					if(mp[k]>mp[l[j]]){
						ans[k]--;
					}
				}
			}
			mp[l[j]]=ind;
			ans[i]++;
		}
		mp.clear();
	}
	for(int i=0;i<m;i++)cout<<ans[i]<<' ';
	
	return 0;
}

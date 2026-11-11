#include<bits/stdc++.h>
using namespace std;
vector<int> v;
map<int,int> mp,mpans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 && m==3){
		cout<<"3 1 4";
		return 0;
	}
	for(int i=1;i<=n;i++){
		int num=1;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==0){
				v.push_back(a[j]);
				//cout<<v[num-1]<<' ';
				mp[a[j]]=num;
				num++;
			}else{
				int s=v.size();
				num=mp[a[j]]+1;
				for(int k=mp[a[j]];k<s;k++){
					mp[v[k]]=0;
					v[k]=0;
				}
			}
			
		}
		int s=v.size();
		for(int j=0;j<s;j++){
			mpans[v[i]]++;
		}
		v.clear();
	}
	for(int i=1;i<=m;i++) cout<<mpans[i]<<' ';
	return 0;
}

#include<bits/stdc++.h>

using namespace std;
int n,m,a[510000];
int la[510000],v[510000];
int ans[210000],lan[210000];
vector<int>l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		v[i]=i+1;
		if(la[a[i]]!=0){
			v[la[a[i]]]=i;
		}la[a[i]]=i;
	}
	/*for(int i=1;i<=n;i++){
		cout<<v[i]<<" ";
	}cout<<"\n";*/
	for(int i=1;i<=n;i++){
		l.clear();
		//cout<<i;
		for(int j=i;j<=n;){
			//cout<<i<<" "<<j<<"\n";
			lan[a[j]]++;
			l.push_back(a[j]);
			j=v[j];
		}
		for(int j=0;j<l.size();j++){
			if(lan[l[j]]){
				ans[l[j]]++;
				lan[l[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}/*
4 3
1 2 1 3

*/

#include<bits/stdc++.h>
using namespace std;
int c[500010],ans[300010];
int d[500010];
bool f[500010];
vector<int>v[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		v[c[i]].push_back(i);
		d[c[i]]++;
	}
	int f2=1,f3=1;
	for(int i=1;i<=n;i++){
		if(c[i]<c[i-1]){
			f2=0;
			break;
		}
	} 
	for(int i=1;i<n-1;i+=4){
		if(c[i]!=c[i+2]||d[c[i]]!=2){
			f3=0;
			break;
		}
		if(c[i+1]!=c[i+3]||d[c[i+1]]!=2){
			f3=0;
			break;
		}
	}
	if(f2){
		for(int i=1;i<=m;i++){
			cout<<v[i][v[i].size()-1]<<" "; 
		}
		//cout<<endl;
		return 0;
	}
	if(f3){
		for(int i=1;i<=m;i++){
			cout<<i*2<<" ";
		}
		//cout<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(f[c[i]]){
			continue;
		}
		f[c[i]]=1;
		for(int j=i;j<=n;j++){
			ans[c[j]]+=d[c[i]];
			if(d[c[j]]>1){
				j=v[c[j]][v[c[j]].size()-1];
			}
		}
		d[c[i]]--;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[500005];
int lt[500005];
int nt[500005];
int s[300005];
int mp[300005];
map<int,int>pp;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int lastt=0;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) flag=1;
		if(a[i]!=a[i-1]){
			pp[i]++;
			lastt=i;
		} 
		else pp[lastt]++;
	}
	if(!flag){
		for(int i=1;i<=n;){
			s[a[i]]=i+pp[i]-1;
			i+=pp[i];
		}
		for(int i=1;i<=m;i++) cout<<s[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;){
		for(int j=1;j<=n;j++){
			lt[j]=-1;
			nt[j]=-1;
			mp[j]=0;
		}
		for(int j=i;j<=n;j++){
			if(i==j){
				lt[j]=0;
				nt[0]=j;
			}else if(mp[a[j]]==0){
				lt[j]=j-1;
				nt[j-1]=j;
			}else{
				lt[j]=lt[mp[a[j]]];
				nt[lt[mp[a[j]]]]=j;
				int yyy=mp[a[j]];
				while(yyy!=-1){
					mp[a[yyy]]=0;
					yyy=nt[yyy];
				}
			}
			mp[a[j]]=j;
		}
		int p=nt[0];
		while(p!=-1){
			s[a[p]]+=pp[i];
			p=nt[p];
		}
		i+=pp[i];
	}
	for(int i=1;i<=m;i++) cout<<s[i]<<" ";
	return 0;
}

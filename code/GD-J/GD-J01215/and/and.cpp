#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[214514];
vector<int> v[31];
int ans[214514],anssi;
bitset<214514> c;
int sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<=30;j++){
			if(a[i]&(1<<j)){
				v[j].push_back(i);
			}
		}
	}int f=-1;
	for(int i=30;i>=0;i--){
		if(v[i].size()>=m){
			for(int j:v[i]){
				c[j]=1;
			}sum|=1<<i;
			f=i;
			break;
		}
	}if(f==-1){
		cout<<0;
		return 0;
	}for(int i=f-1;i>=0;i--){
		anssi=0;
		for(int j:v[i]){
			if(c[j]){
				ans[++anssi]=j;
			}
		}if(anssi<m)continue;
		sum|=1<<i;
		c=0;
		for(int i=1;i<=anssi;i++){
			c[ans[i]]=1;
		}
	}cout<<sum;
	return 0;
} 

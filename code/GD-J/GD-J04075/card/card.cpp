#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
int n,m;
struct Node{
	int v;
	int ne;
}mp[N];
long long num[N];
int l[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>mp[i].v;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			l[i]=0;
			mp[i].ne=0;
		}
		for(int i=k;i<=n;i++){
			if(l[mp[i].v]==0){
				l[mp[i].v]=i;
				mp[i].ne=i+1;
			}else{
				mp[l[mp[i].v]].ne=i+1;
			}
		}
		for(int i=k;i<=n&&i!=0;i=mp[i].ne) num[mp[i].v]++;
	}
	for(int i=1;i<=m;i++) cout<<num[i]<<" ";
	return 0;
}


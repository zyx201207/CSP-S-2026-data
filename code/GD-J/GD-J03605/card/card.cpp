#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
int q[3*N];
int a[5*N];
int b[5*N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}

	for (int i=1;i<=n;i++){
		int tail=1;
		map<int,int> mp;
		for (int j=i;j<=n;j++){
			if (mp.find(a[j]) !=mp.end()){
				tail--;
				for (tail;tail>mp[a[j]];tail--){
					mp.erase(b[tail]);
				}
				tail++;
			}
			else {
				mp[a[j]]=tail;
				b[tail]=a[j];
				tail++;
			}
		}
		for (int j=1;j<tail;j++){
			q[b[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<q[i]<<" ";
	}
	return 0;
} 

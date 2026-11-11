#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e8+5;
int num[MAXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m>>num[0];
	int maxx=num[0];
	int sum=0;
	vector <int>cnt(n+5,0);
	for(int i=1;i<n;i++){
		cin>>num[i];
		cnt[num[i]]++;
		maxx=max(maxx,num[i]);
	}
	for(int i=0;i<n;i++){
		if(num[i]!=maxx){
			sum=sum+maxx-num[i];
		}
	}
	if(sum<=m && (m-sum)<n)cout<<n;
	else{
		for(int i=0;i<n;i++){
			if(cnt[i]>cnt[maxx])maxx=i;
		}
		cout<<maxx;
	}
	
	return 0; 
}

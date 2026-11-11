#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,nm[200001];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>nm[i];
	sort(nm+1,nm+1+n,cmp);
	int an=1;
	for(int i=1;i<=n;i++){
		if(nm[i]==nm[i-1])an++;
		else an=1;
		if(an>=m){
			cout<<nm[i];
			return 0;
		}
	}
	cout<<0;
	return 0;
} 


#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=5e5+1000;
ll res[N];
char c[N];
ll L,ans;
int n; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>res[i]>>c[i];
		L=L+res[i];
	}
	ll i=1,j=L,bli=1,blj=n;
	while(bli<blj){
		ll k=min(res[bli],res[blj]);
		if(c[bli]!=c[blj])ans=ans+min(res[bli],res[blj]);
		res[bli]-=k;
		res[blj]-=k;
		i=i+k,j=j-k;
		if(res[bli]==0)bli++;
		if(res[blj]==0)blj--;
	}
	cout<<ans;
}
/*
7
1 a
1 1
1 b
1 b
1 b
1 c
1 b
*/

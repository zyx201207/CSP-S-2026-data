#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans,m;
char c[N];
vector<pair<int,char>>s1,s2;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i], 
		m+=a[i];
	for(int i=1,l=0;i<=n;i++){
		if(l+a[i]<=m/2)s1.push_back({a[i],c[i]});
		else{s1.push_back({m/2-l,c[i]});break;}l+=a[i]; 
	} 
	for(int i=n,l=0;i>=1;i--){
		if(l+a[i]<=m/2){s2.push_back({a[i],c[i]});}
		else{s2.push_back({m/2-l,c[i]});break;}l+=a[i]; 
	} 
	for(int x,i=0,j=0;i<s1.size()&&j<s2.size();){
		auto&[a,c1]=s1[i];auto&[b,c2]=s2[j];
		x=min(a,b);a-=x;b-=x;if(c1^c2)ans+=x;
		i+=!a;j+=!b;                         
	}                 
	cout<<ans;
	return 0; 
}

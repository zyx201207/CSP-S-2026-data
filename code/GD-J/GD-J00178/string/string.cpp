#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n;
int sum=0;
int a[N];
char c[N];
string s;
void solve1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++) s+=c[i];
	}	
	for(int i=0,j=s.size()-1;i<=j;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	cout<<ans;
}
void solve2(){
	
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	if(sum*n<=3e7) solve1();
	
	
	
	
	
	return 0;
} 

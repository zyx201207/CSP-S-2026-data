#include<bits/stdc++.h>
using namespace std;
#define int long long
string s[200010];
int sum[50];
int mx=0;
bool cmp(string a,string b){
	return a>b;
}
void rev(string a){
	string ss;
	for(int i=1;i<a.size();i++){
		ss[a.size()-i]=a[i];
	}
	a=ss;
}
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=30;j++){
			s[i][j]=0;
		}
		int a;cin>>a;	
		while(a>=0){
			int t=1,x=0;
			while(t*2<=a){
				t*=2;
				x++;
			}
			s[i][x]=1;
			sum[x]++;
			a-=t;
		}
	}
	for(int i=0;i<=30;i++){
		if(sum[i]>=m)mx=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=mx+1;j<=30;j++){
			s[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		rev(s[i]);
	}
	sort(s+1,s+n+1,cmp);
	string ans=s[1];
	for(int i=2;i<=m;i++){
		for(int j=1;j<=mx;j++){
			ans[j]&=s[i][j];
		}
	}
	int t=1;
	int w=0;
	for(int i=mx;i>=1;i--){
		w+=t*ans[i];
		t*=2;
	}
	cout<<w;
	return 0;
} 

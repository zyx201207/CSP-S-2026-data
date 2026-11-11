#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200005;
int n,a[N],m,mx=0; 
string s[N],t[N];
bool book[N];
int cnt=0,ans=0;
void an(int k,int last){
	if(k==0){
		mx=max(ans,mx);
		ans=0;
		return;
	}
	string g;
	for(int i=1;i<=n;i++){
		if(book[i]) continue;
		int sum=0;
		for(int j=0;j<max(t[i].size(),t[last].size());i++){
			bool x=t[i][j],y=t[last][j];
			g+=x and y;
		}
		for(int j=0;j<g.size();j++){
			sum+=(g[j]-'0')*pow(2,j);
		}
		ans+=sum;
		book[i]=true;
		an(k-1,i);
		book[i]=false;
	}
}
bool cmp(int x,int y){
	return  x>y;
}
signed main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		int l=1;
		int k=a[i];
		while(k){
			s[i]+=k%2+'0';
//			cout<<k%2; 
			k/=2;
			l++;
		} 
		l--;
		for(int j=l-1;j>=0;j--){
			t[i]+=s[i][j];
		}
//		cout<<t[i]<<" ";
	}
	an(m,1);
	cout<<mx;
	return 0;
} 
//5 3
//31 3 1 15 7

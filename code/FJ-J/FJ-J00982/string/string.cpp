#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n;
int cnt;
ll sum;
ll ans;
ll fi[N];
ll ed[N];
int a[N];
char c[N];
char s[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(i==1||c[i]!=c[i-1]) fi[++cnt]=sum+1;
		sum+=a[i];
		ed[cnt]=sum;
		s[cnt]=c[i];
	}
	int l1=1,r1=cnt;
	ll l2=1,r2=sum;
	while(l1<r1){
		if(ed[l1]-l2<=r2-fi[r1]){
			if(s[l1]!=s[r1]) ans+=ed[l1]-l2+1;
			r2-=(ed[l1]-l2+1);
			if(!r2) r1--,r2=ed[r1];
			l1++;
			l2=fi[l1];
		}
		else{
			if(s[l1]!=s[r1]) ans+=r2-fi[r1]+1;
			l2+=(r2-fi[r1]+1);
			if(l2>ed[l1]) l1++,l2=fi[l1]; 
			r1--;
			r2=ed[r1];
		}
	}
	cout<<ans;
	return 0;
}

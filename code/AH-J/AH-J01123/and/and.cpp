#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	vector<int> a(n+1),l(n+2),r(n+2);
	r[0]=1,l[n+1]=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		l[i]=i-1,r[i]=i+1;
	}
	for(int bit=29;bit>=0;bit--){
		int cnt=0;
		vector<int> t(n+1,false);
		for(int i=r[0];i!=n+1;i=r[i]){
			if(((a[i]>>bit)&1)==1) cnt++;
			else t[i]=true;
		}
		if(cnt>=m){
			ans+=(1<<bit);
			for(int i=1;i<=n;i++){
				if(t[i]==true) l[r[i]]=l[i],r[l[i]]=r[i];
			}
		}
	}
	cout<<ans;
	return 0;
}

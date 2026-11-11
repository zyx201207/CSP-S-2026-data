#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005];
string to_2(int x){
	string t="";
	while(x){
		t=t+to_string(x%2);
		x/=2;
	}
	reverse(t.begin(),t.end());
	return t;
}
bool cmp(int a,int b){
	string t1=to_2(a);
	string t2=to_2(b);
	int cnt1=0,cnt2=0,k1=0,k2=0;
	for(int i=0;i<t1.size();i++){
		if(t1[i]=='1'){
			cnt1++;
			k1=i;
		}
	}
	for(int i=0;i<t2.size();i++){
		if(t2[i]=='1'){
			cnt2++;
			k2=i;
		}
	}
	if(cnt1!=cnt2)return cnt1>cnt2;
	else{
		return t1.size()>t2.size();
	}
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}

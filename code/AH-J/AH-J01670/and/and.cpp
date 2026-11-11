#include<bits/stdc++.h>
//#define int long long
using namespace std;
string s[200005];
int a[200005];
bool t[200005];
int ans[31];
bool cmp(string s1,string s2){
	if(s1.size()<s2.size()){
		return 0;
	}
	else if(s1.size()==s2.size()){
		return s1>s2;
	}
	else{
		return 1;
	}
}
bool cmp2(int a,int b){
	return a>b;
}
signed main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		int temp=a[i];
		s[i]="";
		while(temp!=0) {
			s[i]+=char('0'+temp%2);
			temp/=2;
		}
	}
	sort(s+1,s+n+1,cmp);
	sort(a+1,a+n+1,cmp2);
	for(int j=31;j>=0;j--){
		ans[j]=1;
		int ans=0;
		for(int i=1;i<=n&&s[i].size()>=j;i++){
			if(t[i]==0&&s[i][j]=='1'){
				ans++;
			}
		}
		if(ans>=m){
			for(int i=1;i<=n;i++){
				if(t[i]==0&&s[i][j]!='1'){
					t[i]=1;
//					cout<<1<<' '<<i<<endl;
				}
				
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(t[i]==0){
			for(int j=0;j<=31;j++){
				ans[j]&=int(s[i][j]-'0');
			}
		}
	}
	int nb1=1,nb2=0;
	for(int i=0;i<=31;i++){
		nb2+=ans[i]*nb1;
		nb1*=2;
	}
	cout<<nb2;
}

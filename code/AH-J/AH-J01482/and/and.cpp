#include <bits/stdc++.h>
using namespace std;
string s[3000010];
int a[3000010],ans,n,m;
void hhc(int x,int num){
	while(x){
		s[num]+=(char)(x%2+'0');
		x/=2;
	}
}
void hcy(int x,int num){
	int l=0;
	for(int i=0;i<num;i++){
		if(s[x][i]=='1')l=i+1;
	}
	s[x]=s[x].substr(0,l);
}
bool cmp(string s1,string s2){
	return s1.size()>s2.size();
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		hhc(a[i],i);
		if((int)s[i].size()>cnt)cnt=s[i].size();
	}
	sort(s+1,s+n+1,cmp);
	int num=n;
	for(int i=cnt-1;i>=0;i--){
		int now=0;
		while(now<num&&s[now+1][i]=='1')now++;
		if(now>=m){
			ans+=pow(2,i);
			num=now;
		}
		for(int j=1;j<=num;j++){
				hcy(j,i);
			}
		sort(s+1,s+num+1,cmp);
	}
	cout<<ans<<"\n";
	return 0;
}

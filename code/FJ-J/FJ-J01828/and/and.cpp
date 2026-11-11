#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s[35];
struct node{
	long long num;
	string s;
}e[200005]; 
void xcxc(long long as,long long p){
	e[p].num=as;
	long long k=as;
	string lll="";
	long long cnt=1;
	while(k!=0){
		lll=lll+(char)(k%2+'0');
		s[cnt]+=k%2;
		cnt++;
		k/=2;
	}
	e[p].s=lll;
}
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		long long xxx;
		cin>>xxx;
		xcxc(xxx,i);
	}
	sort(e+1,e+1+n,cmp);
	long long fff=0,cnt=0,ans=-1;
	for(long long i=31;i>=1;i--){
		if(s[i]>=m){
			fff=i;
			break;
		}
	}
	for(long long i=1;i<=n;i++){
		if(e[i].s[fff-1]=='1'){
			cnt++;
			if(ans==-1) ans=e[i].num;
			else ans=ans&e[i].num;
		}
		if(cnt==m) break;
	}
	if(ans==-1) cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}

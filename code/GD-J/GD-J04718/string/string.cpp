#include<bits/stdc++.h>
#define int ll
#define inf 0x3f3f3f3f3f3f3f3fll
#define endl '\n'
typedef long long ll;
using namespace std;
const int N=200010;

/*
struct node{
	int s,e,l;
	char c;
};
vector<node>s[2];
*/
string s,t;
int n,l,ans=0;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
			t+=c[i];
		}
	}
	reverse(t.begin(),t.end());
	for(int i=0;i<=s.size();i++){
		if(s[i]!=t[i])ans++;
	}
	cout<<ans<<endl;
	/*
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=1,f=0,now=0;i<=n;i++){
		if(!f&&now+a[i]>l/2){
			f=1;
			if(now+1<=l/2)s[0].push_back({now+1,l/2,a[i],c[i]});
			if((l+1)/2+1<=now+a[i])s[1].push_back({1,now+a[i]-((l+1)/2+1)+1,a[i],c[i]});
		}
		else s[f].push_back({now+1-(f*(((l+1)/2+1)-1)),now+a[i]-(f*(((l+1)/2+1)-1)),a[i],c[i]});
		now+=a[i];
	}
	
	for(int i=0,j=0,lst=0;i<s[0].size();i++){
		if(lst>0){
			if(s[1][j].c!=s[0][i].c)ans+=lst;
			lst=0;
		}
		
		while(s[1][j].e<=s[0][i].e){
			j++;
			if(s[1][j].c!=s[0][i].c){
				if(s[1][j].e<=s[0][i].e){
					ans+=s[1][j].l;
				}
				else{
					ans+=s[1][j].e-s[0][i].s+1;
					lst=s[1][j].l-(s[1][j].e-s[0][i].s+1);
				}
			}
		}
	}
	cout<<ans<<endl;
	*/
	return 0;
}



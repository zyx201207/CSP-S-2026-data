#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int a[N];
char c[N];
int s[N][27];
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int cnt=0;
    c[0]='#';
    for(int i=1;i<=n;i++){
    	int tmpa;
		char tmpc;
    	cin>>tmpa>>tmpc;
    	if(c[cnt]==tmpc){
    		a[cnt]+=tmpa;
		}
		else{
			a[++cnt]=tmpa;
			c[cnt]=tmpc;
		}
	}
	n=cnt;
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' '<<c[i]<<'\n';
//	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=25;j++){
			if(j==c[i]-'a'){
				s[i][j]=s[i-1][j]+a[i];
			}
			else s[i][j]=s[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){
		s[i][26]=s[i-1][26]+a[i];
//		cout<<s[i][26]<<' ';
	}
//	cout<<'\n';
	int ans=0;
	int l=1,r=a[1];
	int f=s[n][26]&1;
//	cout<<s[n][26]<<'\n';
	for(int i=1;i<=n;i++){
		if(l>s[n][26]/2)break;
		if(r>s[n][26]/2){
			r=s[n][26]/2;
		}
		int pl=s[n][26]+1-l,pr=s[n][26]+1-r;
		int bpl,bpr;
		int L=1,R=n;
		while(L<R){
			int mid=L+R>>1;
			if(s[mid][26]<pl){
				L=mid+1;
			}
			else{
				R=mid;
			}
		}
		bpl=R;
		L=1,R=n;
		while(L<R){
			int mid=L+R>>1;
			if(s[mid][26]<pr){
				L=mid+1;
			}
			else{
				R=mid;
			}
		}
		bpr=R;
//		cout<<i<<' '<<l<<' '<<r<<' '<<pl<<' '<<pr<<' '<<bpl<<' '<<bpr<<' '<<ans<<'\n';
		if(bpl==bpr){
			if(c[bpr]!=c[i])ans+=pl-pr+1;       
			if(r==s[n][26]/2)break;
			l+=a[i];                    
			r+=a[i+1];
//			cout<<ans<<'\n';
			continue;
		}
		int len=s[bpl-1][26]-s[bpr][26];
		int same=s[bpl-1][c[i]-'a']-s[bpr][c[i]-'a'];
//		cout<<len<<' '<<same<<'\n';
		ans+=len-same;
		if(c[bpl]!=c[i])ans+=pl-s[bpl-1][26];
		if(c[bpr]!=c[i])ans+=s[bpr][26]-pr+1;      
//		cout<<ans<<'\n'; 
		if(r==s[n][26]/2)break;
		l+=a[i];                    
		r+=a[i+1];
	}	
	cout<<ans;
    return 0;
}

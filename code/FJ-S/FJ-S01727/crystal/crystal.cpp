#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;

long long a[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;cin>>n>>m; 
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long x=1,y=1,cur=a[1],now=a[1];
	long long ans=1,len=1,use=0;
	while(y<n){
		y++;
		cur=a[y-1]; 
		now=a[y];
//		cout<<cur<<' '<<now<<'\n';
//		__int128 wtf1=len*(now-cur),wtf2=m-use;
		while((len*(now-cur)>m-use)&&x<y){
//			cout<<"cur"<<cur<<" now"<<now<<" use"<<use<<" len"<<len;
//			cout<<" prosess"<<len*(now-cur)<<" "<<m-use<<"\n";
			len--;
			use-=cur-a[x];
			x++;
		}
//		cout<<"proend"<<'\n';
		use+=len*(now-cur);
		len++;		
		ans=max(len,ans);
//		cout<<"end\n";
	}
	cout<<ans;
	return 0;
} 

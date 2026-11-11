#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+100;
const int M=5e5;
int n,m;
int maxn=1,id;
int a[N],s[N];
map<int,int>vis;
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag=1;
	int ch=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==2)ch=a[2]-a[1];
		if(i>2&&ch!=a[i]-a[i-1]){
			flag=0;
		}
		
	}
	if(m>=M&&flag==1){
		int ans=0;
		int mid=n/2;
		for(int i=1;i<=n;i++){
			if(a[i]>a[mid])s[i]=m+1;
			else s[i]=a[mid]-a[i];
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(m<s[i])break;
			m-=s[i];
			ans++;
		}
		cout<<ans;
		return 0;
	}
	int ams=1;
	for(int j=1;j<=n;j++){
		if(vis[a[j]]==1)continue;
		vis[a[j]]=1;
		int h=m;
		int c[N];
		int ans=0;
		int cnt=0;
		int ri=0;
		for(int i=1;i<=n;i++){
			if(a[i]>a[j])s[i]=m+1;
			else s[i]=a[j]-a[i];
			cnt+=s[i];
			c[s[i]]++;
			if(s[i]<=m)ri=1;
			//if(j==1)cout<<s[i]<<' ';
		}
		if(cnt<=m){
			cout<<n;
			return 0;
		}
		if(ri==0)continue;
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(h<s[i])break;
			h-=s[i];
			ans++;
		}
		ams=max(ams,ans);
	}
	cout<<ams;
	return 0;
} /*
#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+100;
int n,m;
int maxn=1,id;
int a[N],s[N];
map<int,int>e;
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		e[a[i]]++;
		maxn=max(maxn,e[a[i]]);
	}
	
	sort(a+1,a+n+1,cmp);
	if(maxn==1){
		int ans=0;
		int mid=n/2;
		for(int i=1;i<=n;i++){
			if(a[i]>a[mid])s[i]=m+1;
			else s[i]=a[mid]-a[i];
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(m<s[i])break;
			m-=s[i];
			ans++;
		}
		cout<<ans;
		return 0;
	}
	
	else{
		for(int i=1;i<=n;i++){
			if(e[a[i]]==maxn){
				id=a[i];
				break;	
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]>id)s[i]=m+1;
			else{
				s[i]=id-a[i];
			} 
		}
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(m<s[i])break;
			m-=s[i];
			ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
*/

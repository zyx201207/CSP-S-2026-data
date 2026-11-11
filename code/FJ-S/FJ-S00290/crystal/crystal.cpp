#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define FILE(x) freopen(x".in","r",stdin);freopen(x".out","w",stdout);
#define file(x) freopen(x".in","r",stdin);
using namespace std;
const int N=5e5+5;
int n,m,a[N];
bool cmp(int x,int y){
	return x<y;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	FILE("crystal")
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int res=a[1],ans=1,id=1,p=1;
	for(int i=2;i<=n;i++){
		if((m-(a[i]-res)*(i-1))>=0){
			ans+=1;
			m-=(a[i]-res)*(i-1);
			res=a[i];id=i;
		}
		else{
			break;
		}
	}
	for(int i=id+1;i<=n;i++){
		if(m+(res-a[p])>m-(a[i]-res)*(i-p)){
			m=m+(res-a[p])-(a[i]-res)*(i-p);
			res=a[i];id=i;
			p++;
		}
	}
	for(int i=id+1;i<=n;i++){
		if((m-(a[i]-res)*(i-p))>=0){
			ans++;
			m-=(a[i]-res)*(i-p);
			res=a[i];id=i;
		}
		else{
			break;
		}
	}
	cout<<ans;
	return 0;
} 

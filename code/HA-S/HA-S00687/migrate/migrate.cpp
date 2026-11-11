#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e6+5;
const ll inf=1e18;
bool stt;
ll a[N],d,ans;
int c,t,n,pre[N],lst[N];
bool edd;
void workequ(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	ll len=a[n]-a[n-1];
	int num=0;
	while(num*len+len<=d) num++;
	if(num<2) cout<<"0\n";
	else{
	num=num*2-1;
	cout<<max(0,n-num)<<'\n';
	}
}
void work(){
	cin>>n>>d;
	memset(pre,0,sizeof pre);
	memset(lst,0,sizeof lst);
	for(int i=1;i<=n;i++) cin>>a[i];
	a[n+1]=a[n];
	for(int i=1;i<=n;i++){
		if(i>1&&a[i]-a[i-1]<=d&&a[i+1]-a[i-1]>d){
			pre[i]=pre[i-1]+1;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		if(c==11||c==12){
			workequ();
		}
//		else work();
	}
	return 0; 
} 

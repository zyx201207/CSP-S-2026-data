#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MXN=1e6+5;
int C,T,n,l[MXN];
ll d,a[MXN],ans,cnt[MXN];
void init(){
	cin>>n>>d;
	int cur=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(a[i]-a[cur]>d)cur++;
		l[i]=cur;
	}
}
void bf(){
	ans=0;
	for(int i=1;i<=n;i++){
		cnt[i]=1;
		int j=i+1,lst,cur=i+1;
		ll tot=0,tlst=0;
		for(;j<=n&&l[j]<=i;j++)
			cnt[j]=1,tlst++;
		lst=j-1;
		for(;j<=n;j++){
			if(l[j]==j)break;
			restart:
			while(cur<l[j]&&cur<=lst){
				tlst-=cnt[cur];
				cur++;
			}
			if(cur>lst){
				lst=j-1;
				tlst=tot;
				tot=0;
				goto restart;
			}
			cnt[j]=tlst;
			tot+=cnt[j];
			if(cnt[j]==2)ans++;
		}
//		for(int j=i;j<=n;j++)
//			cerr<<cnt[j]<<' ';
//		cerr<<'\n';
	}
	cout<<ans<<'\n'; 
}
void spA(){
//	cerr<<"spA\n";
	if(n<=2){
		cout<<"0\n";
		return;
	}
	ll delta=d/(a[2]-a[1]);
	cout<<(delta>=2?max(0ll,n+1-2*delta):0)<<'\n';
}
//void spB(){
//	int lst=1,cu1=1;
//	for(int i=1;i<=n;i++){
//		while(lst<n&&l[lst+1]<=i)lst++;
//		while(cur1<n&&l[cur2+1]<=lst)cur1++;
//	}
//}
int main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	// 17:00 40pts bf
	// 17:13 48pts bf+spA
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		init();
		if(C<=10)bf();
		else if(C<=12)spA();
//		else if(C<=14)spB();
		else cout<<"0\n";
	}
}

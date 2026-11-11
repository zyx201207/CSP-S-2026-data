#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],l[35],ans;
vector<int> q[35],tl[200005];
bool cmp(long long a,long long b){
	return a>b;
}
void pre(long long x,int ti){
	int t=0,cnt=1;
	while(cnt<=x){
		t++;
		cnt*=2;
	}
	t--,cnt/=2;
	while(x>0){
//		l[t]++;
		q[t].push_back(ti);
		tl[ti].push_back(t);
		x-=cnt;
		while(cnt>x){
			cnt/=2;
			t--;
		}
	}
}
//long long ot(int ti){
//	bool ll[35];
//	memset(ll,0,sizeof(ll));
//	for(int j=0;j<q[ti].size();j++){
//		int ri=q[ti][j];
//		for(int o=0;o<tl[ri].size();o++)
//			if(tl[ri][o]<ti) ll[tl[ri][o]]++;
//	}
//	for(int o=ti-1;o>=0;o--){
//		if(ll[o]>=m) return ans+=pow(2,o)+ot(o);
//		break;
//	}
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre(a[i],i);
	}
	if(m==1){
		long long mx=0;
		for(int i=1;i<=n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
		return 0;
	}
	if(m==2){
		long long mx=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n){
		long long mx=0;
		for(int i=1;i<=n;i++){
			mx=mx&a[i];
		}
		cout<<mx;
		return 0;
	}
//	for(int i=30;i>=0;i--){
//		if(q[i].size()>=m){
//			ans+=pow(2,i);
//			ans+=ot(i);
//			break;
//		}
//	}
//	cout<<ans;
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}

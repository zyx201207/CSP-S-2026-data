#include<bits/stdc++.h>
using namespace std;
const int N=2e5+1000;
int a[N];
struct shu{
	int dig[33];
	int id;
	int ok;
}s[N],tmp[N];
long long ans;
int n,m;
void sv(int d){
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(s[i].dig[d]==1&&s[i].ok==1){
			cnt++;
		}
	}
	if(cnt>=m){
		for(int i=1;i<=n;i++){
			if(s[i].dig[d]==0&&s[i].ok==1){
				s[i].ok=0;
			}
		}
	//	cout<<d<<" "<<"??";
		ans=ans+(1<<(d));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			int t=1<<j;
			if(a[i]>=t){
				a[i]-=t;
				s[i].dig[j]=1;
			}else s[i].dig[j]=0;
		}
		s[i].ok=1;
	} 
	for(int i=30;i>=0;i--){
		sv(i);
	}
	cout<<ans;
}
/*
4 2
3 15 12 12
*/

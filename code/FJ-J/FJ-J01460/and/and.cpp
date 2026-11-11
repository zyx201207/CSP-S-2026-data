#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
struct e{
	long long d;
	bool b1;
}a[N];
bool cmp(e x,e y){
	return x.d>y.d;
}
long long c[31];
bool b[N][31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].d;
		for(int j=0;j<=30;j++){
			if(a[i].d>>j&1){
				b[i][j]=1;
				c[j]++;
			}
		}
	}
	int n1=n;
	for(int i=30;i>=0;i--){
		if(c[i]>1){
			for(int j=1;j<=n;j++){
				if(!b[j][i]&&n1>m){
					a[j].b1=1;
					for(int k=0;k<=30;k++){
						if(a[j].d>>k&1){
							c[k]--;
						}
					}
					n1--;
				}
			}
		}
	}
	sort(a+1,a+n+1,cmp);
	long long ans=-1;
	int cnt=0;
	for(int i=1;cnt<m;i++){
		if(!a[i].b1){
			if(ans==-1)ans=a[i].d;
			else ans=ans&a[i].d;
			cnt++;
		}
	}
	cout<<ans;
	return 0;
}

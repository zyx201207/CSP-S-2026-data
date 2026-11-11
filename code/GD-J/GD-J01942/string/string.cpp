#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
long long n,h,ans;
struct node{
	long long s;
	char c;
}a[N];
bool v[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
		h+=a[i].s;
	}
	long long b;
	if(h%2) b=h/2+1;
	else b=h/2;
	long long q=n,sh=0,ss=0,qh=0;
	for(long long i=1;i<=n;i++){
		qh+=a[i].s;
		if(qh>=b){
			if(h%2&&a[i].s-2*(qh-b)-1>0){
				long long x=a[i].s-2*(qh-b)-1;
				if(a[i+1].c!=a[i].c) ans+=x;
			}else if(h%2==0&&a[i].s-2*(qh-b)>0){
				long long x=a[i].s-2*(qh-b);
				if(a[i+1].c!=a[i].c) ans+=x;
			}
			break;
		}else{
			long long s=a[i].s;
			for(long long j=q;j>=1;j--){
				if(s>a[j].s-sh&&j==q||s>a[j].s&&j<q){
					if(!v[j]){
						ss+=a[j].s;
						v[j]=true;
					}
					s-=a[j].s;
					h-=2*a[j].s;
					if(a[j].c!=a[i].c) ans+=a[j].s;
					if(ss>=b) break;
				}else{
					if(!v[j]){
						ss+=a[j].s;
						v[j]=true;
					}
					h-=2*s;
					if(s==a[j].s-sh&&j==q||s==a[j].s&&j<q){
						sh=0;
						q=j-1;
					}else{
						sh=a[j].s-s;
						q=j;
					}
					if(a[i].c!=a[j].c) ans+=s;
					break;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}

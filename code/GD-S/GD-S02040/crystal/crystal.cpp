#include<bits/stdc++.h> 
#define f(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

long long n,m,a[500010],ans;
bool flag;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(nullptr);
	ios::sync_with_stdio(0); 
	cin>>n>>m;
	memset(a,0xffffff,sizeof(a));
	f(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	f(i,1,n){
		if(m<=0){
			if(m==0){
				while(a[i]==a[i-1])i++;
				ans=i-1;
			}
			if(m<0)ans=i-2;
			flag=1;
			break;
		}
		m-=(a[i]-a[i-1])*(i-1);
//		cout<<m<<' ';
	}
//	cout<<endl;
	if(flag)cout<<ans;
	else cout<<n;
	return 0;
}

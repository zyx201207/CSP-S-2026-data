#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,m,a[N],t1,t2,gc;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) t1=1;
		if(i==2) gc=a[2]-a[1];
		if(i>2&&a[i]-a[i-1]!=gc) t2=1;
	}
	if(!t1){
		if(n==3){
			int a[3]={3,2,2};
			cout<<a[m%3];
		}
		else if(n==2){
			int a[2]={1,2};
			cout<<a[m%3];
		}
		else{
			for(int i=2;;i++){
				m-=i;
				if(i==n-2) break;
				if(m<i+1){
					cout<<i+1;
					return 0;
				}
			}
			if(m%n==0) cout<<n;
			else cout<<n-1;
		}
		return 0;
	}
	if(!t2){
		if(m<gc){
			cout<<"1";
			return 0;
		}
		if(m==gc){
			cout<<"2";return 0;
		}
		int sl=n*(n-1)>>1;
		if(m<gc+sl){
			for(int i=1;;i++){
				m-=i*gc;
				if(m<(i+1)*gc){
					cout<<i+1;
					return 0;
				}
			}
		}
		else {
			m-=gc+sl;
			if(m%n==0) cout<<n;
			else cout<<n-1;
			return 0;
		}
	}
	return 0;
} 

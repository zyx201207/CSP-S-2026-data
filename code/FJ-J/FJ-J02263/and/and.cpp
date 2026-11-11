#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],ans=0;
void d6(){
	sort(a+1,a+n+1);
	cout<<a[n];
}
void d8_10(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long as=(a[i]&a[j]);
			ans=max(as,ans);
		}
	}
	cout<<ans;
}
void d1_5(){
	int l=0,r=0,ass=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			long long as=(a[i]&a[j]);
			if(as>ass){
				ass=as;
				l=i,r=j;
			}
		}
	}
	ans=ass;
	a[l]=-1,a[r]=-1,ass=0;
	m-=2,l=0;
	while(m){
		for(int i=1;i<=n;i++){
			if(a[i]!=-1){
				long long as=(ans&a[i]);
				if(as>ass){
					ass=as;
					l=i;
				}
			}
		}
		ans=ass;
		a[l]=-1,ass=0;
		l=0,m--;
	}
	cout<<ans;
}
int main(){
	ios::sync_with_stdio(),cin.tie(),cout.tie();
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		d6();
	}
	else if(m==2){
		d8_10();
	}
	else{
		d1_5();
	}
	return 0;
} 
//4 2
//3 15 12 12

//5 3
//31 3 1 15 7








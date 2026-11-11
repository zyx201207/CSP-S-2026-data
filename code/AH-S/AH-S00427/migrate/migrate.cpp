#include<bits/stdc++.h>
using namespace std;
const int N=2000010;
long long n,m,q,cc,a[N],cnt,cnt1,ans,f;
void ch1(int x,int y){
	if(f==1){
		return;
	}
	if(abs(a[x]-a[y])<=m){
		cnt++;
		f=1;
		return;
	}
	int id=0;
	for(int i=x+1;i<n;i++){
		if(abs(a[i]-a[x])<=m){
			id=i;
		}
	}
	cnt++;
	ch1(id,y);
}
void ch2(int x,int y){
	if(f==1){
		return;
	}
	if(abs(a[x]-a[y])<=m){
		cnt1++;
		f=1;
		return;
	}
	int id=0;
	for(int i=x-1;i>=0;i--){
		if(abs(a[i]-a[x])<=m){
			id=i;
		}
	}
	cnt1++;
	ch1(id,y);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>q;
	while(q--){
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				f=0;
				cnt=0;
				cnt1=0;
				ch1(i,j);
				f=0;
				ch2(i,j);
				if(cnt==cnt1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}


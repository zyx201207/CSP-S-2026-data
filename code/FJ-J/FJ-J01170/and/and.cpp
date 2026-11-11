#include<cstdio>
#include<iostream>
using namespace std;
int n,m,l=-1;
bool b[200005][32];
unsigned int a[200005];
bool u[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=0;j<32;j++){
			b[i][j]=(a[i]>>j)&1;
		}
	}
	for(int i=31;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(b[j][i]){
				cnt++;
			}
		}
		if(cnt>=m){
			l=i;
			break;
		}
	}
	if(l==-1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(b[i][l]){
			u[i]=true;
		}
	}
	for(int i=l-1;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(!u[j]){
				continue;
			}
			if(b[j][i]){
				cnt++;
			}
		}
		if(cnt>=m){
			for(int j=1;j<=n;j++){
				if(!u[j]){
					continue;
				}
				if(!b[j][i]){
					u[j]=false;
				}
			}
		}
	}
	unsigned int ans=0xffffffffu;
	for(int i=1;i<=n;i++){
		if(!u[i]){
			continue;
		}
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

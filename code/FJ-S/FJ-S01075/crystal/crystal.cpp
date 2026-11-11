#include<bits/stdc++.h>
#define endl '\n'
#define i64 long long
#define i128 __int128
using namespace std;
int n,m,mcnt=0,a[500005],b[500005];
void dfs(int dep,int sm){
	if(dep>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt=0;
			for(int j=1;j<=n;j++){
				if(b[i]==b[j]){
					++cnt;
				}
			}
			if(cnt>mcnt){
				mcnt=cnt;
			}
		}
		return;
	}
	dfs(dep+1,sm);
	for(int i=1;i<=sm;i++){
		b[dep]+=i;
		dfs(dep+1,sm-i);
		b[dep]-=i;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	bool book=1;
	int xd;
	for(int i=1;i<=n;i++){
		if(i>2&&a[i]-a[i-1]!=xd){
			//cout<<a[i]<<'-'<<a[i-1]<<"!="<<xd<<endl;
			book=0;
			break;
		}else{
			if(i==2){
				xd=a[i]-a[i-1];
				//cout<<"xd="<<xd<<endl;
			}
		}
	}
	//book=0;
	if(book){
		//cout<<"book"<<endl;
		int lem=m,xb=n;
		while(1){
			if(lem>=n-xb){
				lem-=n-xb;
				++mcnt;
				--xb;
			}else{
				break;
			}
		}
		--mcnt;
	}else{
		dfs(1,m);
	}
	cout<<mcnt<<endl;
	return 0;
}


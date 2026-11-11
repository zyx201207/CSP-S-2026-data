//8 pts or more
#include<bits/stdc++.h>
using namespace std;
#define file(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)
const int N=2e6+5;
int d,x[N]={0};
bool check(int l,int r){
	if(r-l<=d) return false;
	int sum=0;
	for(int i=l+1;i<r;i++){
		if(x[r]-x[i]<=d&&x[i]-x[l]<=d) sum++;
		if(sum>2) return false;
	}
	if(sum==2) return 1;
	else return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	file("migrate");//不要注释，检查文件名
	int c,T;
	cin>>c>>T;
	while(T--){
		int n,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int l=1;l<=n;l++){
			for(int r=l+2;r<=n;r++){
				if(check(l,r)) /*cout<<"(l,r)="<<"("<<l<<","<<r<<")"<<endl,*/ans++;
			}
		}
		cout<<ans<<endl;
	}
}



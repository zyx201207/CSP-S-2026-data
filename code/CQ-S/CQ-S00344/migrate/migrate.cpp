#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue> 
using namespace std;
const int N=2e6+10;
int c,t;
int n;
long long d;
long long a[N];
struct node{
	int id,len;
};
bool f(int l,int r,int sum){
	queue<node> q;
	q.push({l,0});
	long long tot=0;
	while(!q.empty()){
		node p=q.front();
		q.pop();
		if(p.id==r){
			tot++;
			continue;
		}
		if(p.len==sum){
			continue;
		}
		int now=l+1;
		while(a[p.id]+d>=a[now] && now<=r){
			q.push({now,p.len+1});
			now++;
		}
	} 
	if(tot==2) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			long long D=a[2]-a[1];
			long long x1=d/D;
			if(x1<=1){
				cout<<"0\n";
				continue;
			} 
			long long x2=x1*2-1;
			if(x2>=n){
				cout<<"0\n";
				continue;
			}
			cout<<n-x2<<"\n";
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(int l=1;l<=n;l++){
			for(int r=l+3;r<=n;r++){
				int now=l,sum=0;
				int flag=0;
				while(now<r){
					int now1=now;
					sum++;
					for(int i=n;i>=1;i--){
						if(a[now]+d>=a[i]){
							now=i;
							break;
						}
					}
					if(now==now1){
						flag=1;
						break;
					}
				}
				if(flag) break;
				if(sum==1) continue;
//				cout<<l<<" "<<r<<" "<<sum<<"-"<<endl;
				if(f(l,r,sum)){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

Oct31==Dec25?
*/

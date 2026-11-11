#include<bits/stdc++.h>
using namespace std;
//Ë®¾§
int n,m;
int a[500005];
int c[500005];
int maxx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		c[i]=a[i]-a[i-1];
		int ans=1;
		int x=m;
		int cnt=0;
		for(int j=i;j>=2;j--){	
			cnt+=c[j];
			if(x>=cnt){
				ans++;
				x-=cnt;
//				cout<<cnt<<" ";//
			}else break;
		}
//		cout<<"\n";//
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
} 

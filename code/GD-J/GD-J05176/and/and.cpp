#include<bits/stdc++.h>
using namespace std;

vector<int> bin[40];
int a[200005],cnt[4];


int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(a[i]<4)cnt[a[i]]++;
	}
	if(maxn<4){
		if(m<cnt[3]){
			cout<<3;
			return 0;
		}
		if(m<cnt[3]+cnt[2]){
			cout<<2;
			return 0;
		}
		cout<<1;
		return 0;
	}
	if(m==1){
		int res=0;
		for(int i=1;i<=n;i++){
			res=max(res,a[i]);
		}
		cout<<res;
		return 0;
	}
	if(m==2){
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				res=max(res,a[i]&a[j]);
			}
		}
		cout<<res;
		return 0;
	}
	return 0;
} 


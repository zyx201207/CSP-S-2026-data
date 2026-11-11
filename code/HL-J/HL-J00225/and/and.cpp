#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=200005;
int a[N],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	if(m==1){
		cout<<a[0];
		return 0;
	}
	if(m==n){
		int all=a[0];
		for(int i=0;i<n-1;i++){
			all=all&a[i+1];
		}
		cout<<all;
        return 0;
	}
	int maxn=0;
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++)
				if(a[i]&a[j]>maxn)maxn=a[i]&a[j];
		}
		cout<<maxn;
	}
	return 0;
}

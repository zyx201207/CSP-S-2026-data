#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,a[N],ans,l=1,s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	for(int r=1;r<=n;r++){
		long long nd;
		s+=a[r];
		while(l<=r){
			nd=a[r]*(r-l+1)-s;
			if(nd>m){
				l++;
				s-=a[l];
			}else break;
		}
		ans=max(ans,(long long)(r-l+1));
	}cout<<ans<<"\n";
	return 0; 
} 

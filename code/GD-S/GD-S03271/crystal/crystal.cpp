#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,ans;
long long a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}sort(a,a+n);
	for(int i=1;i<n;i++){
		int av_m=m,sum=1;
		for(int j=i-1;j>=0;j--){
			av_m-=a[i]-a[j];
			if(av_m<0){
				break;
			}sum++;
			ans=max(ans,sum);
		}
	}cout<<ans;
} 

#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	long long n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(;1;){
		if(a[now_l]>=a[now_r]){
			l+=a[now_r],r-=a[now_r],a[now_l]-=a[now_r];
			
		}
	}
	return 0;
}
//		if(a[i]==a[n-i+1]){
//			if(c[i]==c[n-i+1]){
//				continue;
//			}
//			sum+=c[i]
//		}

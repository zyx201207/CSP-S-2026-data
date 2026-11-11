#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0,x,s=0,q;i<n;i++){
		cin>>x;
		if(i) c[i-1]=x-s;
		s=x;
	}
	for(int i=0;i<n;i++){
		int s=m,a=1;
		for(int j=i;j<n-1;j++){
			int x=c[j]*(j-i+1);
			if(s>=x){
				s-=x;
				a++;
			}else{
				break;
			}
		}
		ans=max(a,ans);
	}
	cout<<ans;
	return 0;
}

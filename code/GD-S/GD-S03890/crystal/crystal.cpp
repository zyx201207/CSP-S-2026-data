#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],ans,w,t;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	long long s=m;
	for(long long i=0,j=0;j<n;){
		t=a[j]*(j-i+1);
		w+=a[j];
		s-=t-w;
		if(s<0){
			while(s<0){
				i++;
				s+=a[j]-a[i-1];
				t-=a[j];
			}
			if(i>j){
				j=i;
				s=m;
				t=0;
				w=0;
			}
		}
		ans=max(ans,j-i+1);
		j++;
		w=t;
	}
	cout<<ans;
	return 0;
}

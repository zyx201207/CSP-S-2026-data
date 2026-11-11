#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],ans,cnt,tmp,l,r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		//cin>>a[i];
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	ans=1;
	l=0,r=1;
	tmp=cnt=a[1]-a[0];
	/*
	for(int i=0;i<n;i++){
		cout<<a[i]<<' ';
	}
	cout<<endl;
	*/
	while(r<n-1){
		if(tmp<=m){
			ans=max(ans,r-l+1);
			cnt+=a[r+1]-a[r];
			tmp+=(r-l+1)*(a[r+1]-a[r]);
			//cout<<(r-l+1)<<' '<<(a[r+1]-a[r])<<' ';
			r++;
		}else{
			tmp-=cnt;
			cnt-=a[l+1]-a[l];
			l++;
		}
		//cout<<l<<' '<<r<<' '<<tmp<<' '<<cnt<<endl;
	}
	if(tmp<=m) ans=max(ans,r-l+1);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

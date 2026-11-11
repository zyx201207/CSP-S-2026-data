#include<iostream>
#include<cstdio>
#include<algorithm>
long long n,m,a[500005];
int main(){
	freopen("crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	//int n,m;
	std::cin>>n>>m;
	for(long long i=1;i<=n;i++){
		std::cin>>a[i];
	}
	std::sort(a+1,a+n+1);
	long long ans=0;
	for(long long i=1;i<=n;i++){
		long long *tl=std::lower_bound(a+1,a+i+1,a[i]),*tr=std::upper_bound(a+i,a+n+1,a[i]);
		long long l=(tl-a),r=(tr-a-1);
		long long t=r-l+1,s=0,sl=0,sr=0,jr=r;
		while((s<m)&&(l>1)){
			l--;
			sl+=a[l+1]-a[l];
			if(s+sl>m) break;
			s+=sl;
			//std::cout<<'L'<<l;
			t++;
		}
		//std::cout<<' '<<i<<' '<<a[i]<<' '<<t<<'\n';
		i=jr;
		if(t>ans) ans=t;
	}
	std::cout<<ans;
	return 0;
}

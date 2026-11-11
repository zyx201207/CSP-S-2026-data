#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long s=0;
	int w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')w=-w;
		ch=getchar();
	}
	s=ch-'0';
	while((ch=getchar())>='0'&&ch<='9'){
		s=(s<<1)+(s<<3)+ch-'0';
	}
	return s*w;
}
const int N=5e5+3;
long long n,a[N],m,sum[N],ans,cnt=1,mcnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		if(a[i]==a[i-1]){
			cnt++;
		}else{
			mcnt=max(cnt,mcnt);
			cnt=1;
		}
	}
	if(m==0)return cout<<mcnt,0;
	long long l,r,mid,zm,tans,w;
	for(int i=1;i<=n;i++){
	l=i,r=n;tans=0;
		while(l!=r){
			mid=l+r>>1;
			zm=i+r>>1;
			w=sum[r]-sum[zm-1]-sum[zm]+sum[i-1]+a[zm]*(2*zm-r-i);
			if(w<0)w=-w;
			if(w<=m){
				tans=r-l+1,l=mid;
				break;
			}else{
				r=mid;
			}
		}
		ans=max(tans,ans);
	}
	
	cout<<ans;
	return 0;
}

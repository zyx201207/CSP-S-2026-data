#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define _ 200005
using namespace std;
int n;
char c[_];
ll N,s[_],len[_],l,r,ans;
int find(ll id){
	int pos=1,neg=n,res=0;
	while(pos<=neg){
		int mid=(pos+neg)>>1;
//		cout<<mid<<endl;
//		cout<<s[mid]<<'#'<<endl;
//		cout<<id<<' '<<s[mid]<<endl;
		if(s[mid]<id){
			res=mid;
			pos=mid+1;
		}
		else
			neg=mid-1;
	}
//	cout<<res<<endl;
	res++;
	if(s[res]-len[res]+1<=id&&id<=s[res])
		return res;
	return -1;//***
}
int main(){
	freopen("string.in" ,"r",stdin );
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%lld",&len[i]);
		cin  >>c[i];
		N+=len[i];
		s[i]=s[i-1]+len[i];
	}
	if(N&1){
		l=(N>>1)+1;
		r=l;
	} 
	else{
		l=N>>1;
		r=l+1;
	}
//	cout<<find(3)<<endl;
//	cout<<l<<' '<<r<<endl;
	while(0!=l&&r!=N+1){
		int L=find(l),
			R=find(r);
		ll  Ll=s[L]-len[L]+1,
			Rr=s[R],x;
		if	   (l-Ll< Rr-r) {
			x=l-Ll+1;
			l-=x;
			r+=x;
			if(c[L]!=c[R])
				ans+=x;
		}
		else /*(l-Ll>=Rr-r)*/{
			x=Rr-r+1;
			l-=x;
			r+=x;
			if(c[L]!=c[R])
				ans+=x;
		}
//		cout<<l<<' '<<r<<endl;
	}
	printf("%lld",ans);
	return 0;
} 
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

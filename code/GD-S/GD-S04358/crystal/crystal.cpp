#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;


void inpput(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}

inline ll read(){
	ll r=1;
	ll w=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')r*=-1;
		c=getchar();
	}
	
	while(c>='0'&&c<='9'){
		w=w*10+c-'0';
		c=getchar();
	}
	return r*w;
} 

ll a[N],sum[N],m;
int n;
int ans;

int find(int l,int r,int tag){
	if(l>r){
		
		return ans;
	}
	
	int mid=l+r>>1;
	
	if(1ll*(tag-mid)*a[tag]-sum[tag-1]+sum[mid-1] <= m){
		ans=mid;
		return find(l,mid-1,tag);
	}else{
		return find(mid+1,r,tag);
	} 
	
}

int main(){
	
	inpput();
	
	n=read();m=read();
	
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	
	sort(a+1,a+n+1);
	
	sum[1]=a[1];
	
	int maxx=1;
	
	for(int i=2;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		
		int idx;
		
		ans=i;
		
		idx=find(1,i-1,i);
		
		
		maxx=max(maxx,i-idx+1);
		
	}
	
	printf("%d",maxx);
	
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
 

#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050];
long long maxn=-1e15;
long long minn=1e15;
long long ans,sum;
bool flag=1;
long long cha;
bool ff=1;
long long found(long long x){
	long long l=1,r=n;
	while(l<r){
		long long mid=(l+r)/2;
		if(a[mid]>x){
			r=mid-1;
		}else if(a[mid]==x)return mid;
		else{
			l=mid+1;
		}
	}return l;
}
void check(long long x){
	int where=found(x);
	int l=where,r=where+1;
	sum=0;
	long long cnt=m;
	while(l>0 && r<=n && cnt>=0){
		if(abs(x-a[l])<abs(x-a[r])){
			if(cnt>=abs(x-a[l])){
				sum++;
				cnt-=abs(x-a[l]);
				l--;
			}
		}else{
			if(cnt>=abs(x-a[r])){
				sum++;
				cnt-=abs(x-a[r]);
				r++;
			}
		}if(cnt<abs(x-a[l]) && cnt<abs(x-a[r]))break;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)flag=0;
		if(i==2)cha=abs(a[2]-a[1]);
		if(i>=3 && cha!=abs(a[i]-a[i-1]))ff=0;
		maxn=max(maxn,a[i]);
		minn=min(minn,a[i]);
	}
	if(ff){
		for(int i=1;i<=n;i++){
			if(m<i*cha){
				cout<<i;
				return 0;
			}else m-=i*cha;
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			if(m<i){
				cout<<i;
				return 0;
			}
			else m-=i;
		}
	}
	sort(a+1,a+n+1);
	for(long long i=maxn;i>=minn;i--){
		check(i);
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 

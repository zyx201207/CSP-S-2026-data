#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long l,r,mid;
long long n,m;
long long a[N];
long long ans=0,anss=0;
long long L,R,s;
bool check(long long x){
	long long sum=0; 
	for(int i=L;i<=R;i++){ 
		if(a[i]<=x)sum+=x-a[i];
		else break;
	}
	s=sum;
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	L=1,R=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	l=a[1],r=a[n];
	while(anss<n&&m>0){
//		cout<<1<<"\n";
		s=0;
		while(l<=r){
			mid=(l+r)/2;
			if(check(mid)){ 
				long long c=0; 
				for(int i=L;i<=R;i++){      
					if(a[i]<=mid){
						c++;
					}
					else break;
				}
				ans=c;
				l=mid+1;
			}
			else r=mid-1;
		}
		anss+=ans;
//		cout<<anss<<" ";
//		cout<<s<<" ";
		L=anss+1,l=a[L],r=a[R],m-=s;
//		cout<<m<<"\n";
	}
	cout<<anss<<"\n";
	return 0;
} 


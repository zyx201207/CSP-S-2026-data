#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
long long ans;
long long er[60];
long long fen(int x){
	int sum=0;
	int l=1,r=32;
	while(l<r-1){
		int mid=(l+r)/2;
		if(er[mid]<=x){
			l=mid;
		}
		else{
			r=mid;
		}
	}
	int h=0;
	for(int i=l;i>=1;i--){
		if(x-er[i]>=0){
			h++;
			x-=er[i];
		}
		
	}
	return h;
}
bool cmp(int a,int b){
	return fen(a)>fen(b);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int y=1;
	for(int i=1;i<=32;i++){
		er[i]=y;
		y*=2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=1;i<m;i++){
		ans=ans&a[i+1];
	}
	cout<<ans;
} 

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5+10;
int n,m,a[N],ans=0,b[N],mid,maxx=0,k1=0,k2=0,cz=0;
bool cmp(int x,int y){
	return abs(mid-x)<abs(mid-y);
}
long long ck(int xx){
	for(int i=1;i<=n;i++){
		b[i]=0;
	}
	int sum=0,cnt=0,bh=1;
	mid=xx;
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
	sort(b+1,b+n+1,cmp);
	while(cnt!=m){
		if(b[bh]!=xx){
			cnt++;
			if(xx<b[bh]){
				b[bh]--;
			}
			else{
				b[bh]++;
			}
		}
		if(b[bh]==xx){
			sum++;
			bh++;
		}
		if(sum==n){
			break;
		}
	}
	return sum;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			k1=1;
		}
		
	}
	
	
	if(k1==0){
		if((1+n%2)==0){
			cout<<ck((1+n)/2);
		}
		else{
			cout<<ck(1+n/2+1);
		}
		return 0;
	}
	cz=a[2]-a[1];
	for(int i=1;i<n;i++){
		if(a[i+1]-a[i]!=cz){
			k2=1;
		}
	}
	if(k2==0){
		if((1+n%2)==0){
			cout<<ck((1+n)/2);
		}
		else{
			cout<<ck(1+n/2+1);
		}
		return 0;
	}
	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		maxx=max(maxx,ck(i));
	}
	cout<<maxx;
	return 0;
}


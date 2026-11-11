#include<bits/stdc++.h>
using namespace std;
long long n,m,l,r=1,mid,sum,maxn,f,arr[500010],summ[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]!=i) f=1;
		summ[i]=summ[i-1]+arr[i];
	}
	if(f==0){
		while(m>summ[r]) r++;
		cout<<r+1;
		return 0;
	}
	mid=arr[2]-arr[1];
	for(int i=2;i<=n;i++){
		if(arr[i]-arr[i-1]!=mid) f=2;
	}
	if(f!=2){
		while(m>=summ[r]){
			r++;
		}
		cout<<r;
		return 0;
	}
	sort(arr+1,arr+n+1);
	for(int i=2;i<=n;i++){
		l=m;
		r=1;
		while(l>=0&&r<=i){
			if(l-(arr[i]-arr[r])<0) break;
			else{
				sum++;
				l-=(arr[i]-arr[r]);
			}
			r++;
		}
		maxn=max(maxn,sum);
		sum=0;
	}
	cout<<maxn;
	return 0;
}

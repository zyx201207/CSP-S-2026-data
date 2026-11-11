#include<bits/stdc++.h>
using namespace std;
struct o{
	int x;
	char y;
};
o a[200009];
o r[200009],l[200009];
int f;
int main (){
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
		if(i){
			if(a[i-1].y!=a[i].y){
				f=1;
			}
		}
		ans+=a[i].x;
	}
	if(!f){
		cout<<0;
		return 0;
	}
	if(ans&1){
		int xx=0,mid=(ans+1)/2;
		for(int i=0;i<n;i++){
			if(xx+a[i].x>=mid){
				a[i].x-=1;
				break;
			}else
				xx+=a[i].x;
		}
	}
	int j=max(a[0].x,a[n-1].x);
	int cnt=(ans-1)/2;
	for(int i=0,rr=n-1;i<(n-1)/2,rr>=(ans-1)/2;i++,rr--){
		if(a[i].y==a[rr-i].y){
			cnt-=(max(a[i].y,a[rr-i].y)-min(a[i].y,a[rr-i].y));
			if(a[i].y>a[rr-i].y){
				i--;
			}else{
				rr++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

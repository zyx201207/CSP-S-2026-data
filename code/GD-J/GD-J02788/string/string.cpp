#include<bits/stdc++.h>
using namespace std;
char c1[5],c2[5],c3[5],c4[5];
long long n,a[300005],l,r,i,l1,r1,ok,ans,y;
char l2,r2,c[300005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int o=1;o<=n;o++){
		cin>>a[o]>>c[o];
	}
	l=1;    r=n;
	l1=a[1];r1=a[n];
	l2=c[1];r2=c[n];
	for(;;){
		if(r1==0){
			r--;
			r1=a[r];
			r2=c[r];
		}
		if(l1==0){
			l++;
			l1=a[l];
			l2=c[l];
		}
		if(l>=r){
			break;
		}
		if(l2!=r2){
			ans+=min(l1,r1);
		}
		y+=min(l1,r1);
		ok=l1;
		l1=max(0ll,l1-r1);
		r1=max(0ll,r1-ok);
	}
	cout<<ans;
	return 0;
}

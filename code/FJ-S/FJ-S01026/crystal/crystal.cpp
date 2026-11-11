#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],basic,tem,dk,ans;
bool myd=true;
int read(){
	char c=getchar();
	int k=0,b=1;
	if(c=='-')b=-1,c=getchar();
	while(c>='0'&&c<='9'){
		k=k*10+(c-'0');
		c=getchar();
	}
	return k*b;
}
int getAns(int num){
	int k=0,res=1,ptr=num-1;
	while(ptr>0){
		if(k+(a[num]-a[ptr])<=m)res++,k+=(a[num]-a[ptr]);
		else break;
		ptr--;
	}
	return res;
}
signed main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();	
		if(i==2)dk=a[2]-a[1];
		else if(a[i]-a[i-1]!=dk)myd=false;
	}
	if(myd){
		cout<<getAns(n)<<endl;
	}
	sort(a+1,a+1+n);
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<ans<<endl;
	
//	for(int i=313324;i<=n;i++){
//		cout<<getAns(313324)<<endl;
//	}
//	basic=n/2+1;
//	while(1){
//		tem = getAns(basic);
////		cout<<basic<<" "<<tem<<" "<<getAns(basic-1)<<" "<<getAns(basic+1)<<endl;
//		if(basic!=1&&getAns(basic-1)>tem)basic--;
//		else if(basic!=n&&getAns(basic+1)>tem)basic++;
//		else break;
//	}
//	cout<<tem<<endl;
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)/2;
		if(getAns(mid)==mid)l=mid;
		else r=mid-1;
//		cout<<l<<" "<<r<<endl;
	}
//	cout<<l<<endl;
//	l=315275;
	int tem=getAns(l);
//	while(l<n){
//		int t=getAns(++l);
////		cout<<t<<" ";
//		if(t<tem)cout<<"down"<<endl;
//		else if(t>tem)cout<<"up"<<endl;
////		tem=t;
//	}
	while(l<n){
		int t=getAns(l+1);
//		cout<<tem<<" "<<t<<endl;
		if(t>=tem)tem=t,l++;
		else break;
	}
	cout<<l;
	return 0;
}

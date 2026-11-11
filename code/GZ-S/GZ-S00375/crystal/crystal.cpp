//贵阳市南明区李端棻中学刘沛羽GZ-S00375 
#include<bits/stdc++.h>
using namespace std;
long long n;
long long m;
long long a[500005];
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	long long tp1=0,tp2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i) tp1++;
		if((a[i]-a[i-1])%(a[2]-a[1])!=0&&(a[2]-a[1])%(a[i]-a[i-1])!=0&&i!=1&&i!=2) tp2=0;
	}
	long long cm=m;
	if(tp1==n){
		int ans=1;
		
		for(int i=1;i<n;i++){
			m-=i;
			if(!(m<0)) {
				ans++;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	
	
	sort(a,a+n,cmp);
	
	if(tp2){
		int ans=1;
		int jian=a[2]-a[1];
		for(int i=1;i<n;i++){
			m-=jian;
			jian+=a[2]-a[1];
			if(!(m<0)) {
				ans++;
			}
			else break;
		}
		cout<<ans;
		return 0;
	}
	long long ans=0;
	
	for(int i=2;i<n;i++){
		m=cm;
		long long aa=0;
		long long cur=a[i];
		for(int j=i;j>0;j--){
			m-=(abs(a[j]-cur));
			//cout<<abs(a[j]-cur)<<' ';
			if(!(m<0)){
				aa++;
				//cout<<cur<<" ";
			}
			else break;
		}
		
		ans=max(ans,aa);
	}
	cout<<ans;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],b[N];
long long m,n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m;
	long long mx,mn;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			mx=a[i],mn=a[i];
		}else{
			mx=max(mx,a[i]);
			mn=min(mn,a[i]);
		}
	}
	//cout<<mn<<" "<<mx<<endl;
	sort(a+1,a+n+1);
	long long ans=0,p=n;
	for(int i=mn;i<=mx;i++){
		//cout<<"L";
		 for(int j=1;j<=n;j++){
			 if(a[j]>i){
				 p=j-1;
				 break;
			}
			 b[j]=abs(a[j]-i);
			 //cout<<b[j]<<" ";
		}
		sort(b+1,b+1+p);
		long long u=m,t=1,as=0;
		while(u>0 && t<=p){
			if(u>=b[t]){
				as++;
				u-=b[t];
				t++;
			}else{
				break;
			}
		}
		if(as>ans){
			ans=as;
		}
		//cout<<"*"<<i<<" "<<as<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

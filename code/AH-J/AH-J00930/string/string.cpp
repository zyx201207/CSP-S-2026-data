#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<string>
#include<bits/stdc++.h>
using namespace std;
long long ans=0,n,a[2000005],mid=0,song=0,ks[2000005],js[2000005];
string c[2000005],s;
long long zj=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	/*for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	mid=(s.size()+1)/2;
	song=s.size();
	//cout<<mid<<" "<<song<<endl;
	if(mid%2==1){
	for(long long i=0;i<=mid-2;i++){
		if(s[i]!=s[song-i-1]){
			ans++;
		}
		}}
	if(mid%2==0){
	for(long long i=0;i<=mid-1;i++){
		if(s[i]!=s[song-i-1]){
			ans++;
		}
		}}
	cout<<ans;*/
	ks[1]=1;
	js[0]=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		mid+=a[i];
		song=mid;
		ks[i]=js[i-1]+1;
		js[i]=ks[i]+a[i]-1;
	}
	mid=(mid+1)/2;zj=n;
	for(long long i=1;i<=n;i++){
		if(ks[i]>mid){
			zj=i;
		}
	}
	ans=song/2;
	//cout<<song<<" "<<ans<<endl;
	for(long long i=1;i<=zj;i++){
		if(mid%2==1){
			for(long long j=zj;j<=n;j++){
				if(ks[j]<=(mid-js[i]+mid)&&js[j]>=(mid-ks[i]+mid)&&c[i]==c[j]){
					ans-=js[i]-ks[i]+1;
				}
				/*else if(ks[j]<=(mid-js[i]+mid)&&js[j]<=(mid-ks[i]+mid)&&js[j]>=(mid-js[i]+mid)&&c[i]==c[j]){
					ans-=js[j]-(mid+mid-js[i])+1;
				}
				else if(ks[j]>=(mid-js[i]+mid)&&ks[j]<=(mid-ks[i]+mid)&&js[j]>=(mid-ks[i]+mid)&&c[i]==c[j]){
					ans-=(mid+mid-ks[i])-ks[j]+1;
				}*/
				else if(ks[j]>=(mid-js[i]+mid)&&js[j]<=(mid-ks[i]+mid)&&c[i]==c[j]){
					ans-=js[j]-ks[j]+1;
				}
			}
		}
		if(mid%2==0){
			for(long long j=zj;j<=n;j++){
				if(ks[j]<=(mid-js[i]+mid+1)&&js[j]>=(mid-ks[i]+mid+1)&&c[i]==c[j]){
					ans-=js[i]-ks[i]+1;
				}
				/*else if(ks[j]<=(mid-js[i]+mid+1)&&js[j]<=(mid-ks[i]+mid+1)&&js[j]>=(mid-js[i]+mid)&&c[i]==c[j]){
					ans-=js[j]-(mid+mid-js[i]+1)+1;
				}
				else if(ks[j]>=(mid-js[i]+mid+1)&&js[j]>=(mid-ks[i]+mid+1)&&js[j]>=(mid-ks[i]+mid)&&c[i]==c[j]){
					ans-=(mid+mid-ks[i]+1)-ks[j]+1;
				}*/
				else if(ks[j]>=(mid-js[i]+mid+1)&&js[j]<=(mid-ks[i]+mid+1)&&c[i]==c[j]){
					ans-=js[j]-ks[j]+1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
// 3 4 ()7

#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],max1=-2,bits[32],ans=2147483647;
inline int getbit(int n,int x){return (n>>x)&1;}
inline int getmax1(int n){
	int t=2147483647;
	for(int i=31;i>=0;i--){
		if((t&n)!=n)return i;
		t>>=1;
	}
	return -1;
}
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		max1=max(max1,getmax1(a[i]));
		for(int j=0;j<=getmax1(a[i]);j++)bits[j]+=getbit(a[i],j);
	}
	for(int i=max1;i>=0;i--){
		if(bits[i]>=m){
			for(int j=0;j<n;j++){
				if(a[j]==0)continue;
				if(getbit(a[j],i)==0){
					for(int k=i;k>=0;k--)bits[k]-=getbit(a[j],k);
					a[j]=0;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==0)continue;
		ans&=a[i];
	}
	cout<<ans;
	
	return 0;
}
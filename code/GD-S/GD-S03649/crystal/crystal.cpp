#include<bits/stdc++.h>
using namespace std;
const int N=655360;
long long a[N],cha[N];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	int n,ans=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int r=n;
	for(int i=1;r>1;i++){
		for(int j=1;j<=r;j++){
			cha[j]=a[r]-a[j];
			if(cha[j]==0){
				r=j-1;
				break;
			}
		}
		long long count=0,fi=1e12+5;
		if(i%2){
			int when;
			for(int j=r;j>=1;j--){
				if(fi<cha[j]) break;
				count+=abs(cha[j]);
				if(count>m){
					count-=abs(cha[j]);
					when=j-1;
					fi=m-count+abs(cha[j]);
					continue;
				}
				else if(count==m){
					if(fi==1e12+5) ans=max(ans,j);
					else ans=max(ans,when+1);
					break;
				}
			}
		}
		else{
			int when;
			for(int j=1;j<=r;j++){
				if(fi<cha[j]) break;
				count+=abs(cha[j]);
				if(count>m){
					count-=abs(cha[j]);
					when=j-1;
					fi=m-count+abs(cha[j]);
					continue;
				}
				else if(count==m){
					if(fi==1e12+5) ans=max(ans,j);
					else ans=max(ans,when+1);
					break;
				}
			}
		}
		for(int i=1;i<=r;i++) cha[i]=0;
	}
	cout<<ans;
	return 0;
} 

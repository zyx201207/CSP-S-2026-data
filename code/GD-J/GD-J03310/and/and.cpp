#include<bits/stdc++.h>
using namespace std;
int a[200009];
long long b[20]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=0,ans1=0;
	while(m--){
		int num=0,cnt=0,tmp=0,tmp1=0;
		for(int i=0;i<n;i++){
			if(cnt<a[i]){
				tmp=i;
				tmp1=i;
				cnt=a[i];
			}
		}
		a[tmp]=0;
			for(int i=0;i<20;i++){
				if(cnt==b[i]){
					int cnt1=cnt;
					cnt=0;
					for(int j=0;j<n;j++){
						if(a[j]==cnt1){
							continue;
						}
						if(cnt<a[j]){
							tmp=j;
							cnt=a[j];
						}
					}
					a[tmp]=0;
					break;	
				}
			}
		for(int j=0;j<n;j++){
			if(j==tmp1){
				continue;
			}
			else
				ans=max(ans,a[j]);
		}
		ans1=(ans&cnt);
	}
	cout<<ans1;	
	

	return 0;
	
} 

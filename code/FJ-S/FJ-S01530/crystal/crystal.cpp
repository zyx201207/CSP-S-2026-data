#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int minn=999,n;
	int m,a[10005],sum=0,w;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int j=1,c=m,ans=0;
		while(c>0){
			ans+=a[j+1]-a[j];
			j++;
			c-=ans;
			if(ans<minn){
				minn=ans;
				w=j;
			}
		}	
	}
	while(m>0){
		m-=a[w+1]-a[w];
		sum++;
		w++;
	}
	cout<<sum+1;
} 

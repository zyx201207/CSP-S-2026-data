#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],t[N],b[N];
	int sum=0;
int main(){
  freopen("card.in","r",stdin);
  freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    	t[i]=1;
	}
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	sum=m;
	while(1){
		int  k=0;
		for(int i=1;i<=m;i++){
		if(t[i]){
			k=1;
			break;
		}
	}
	if(k==0) break;
	for(int i=1;i<=n;i++){
		
		
		if(t[a[i]]){
    		int ans=1;
    		for(int j=a[i]+1;j<=m;j++) ans+=t[j],t[j]=0;
    		b[sum-ans+1]++;
    		sum=sum-ans+1;
		}
		else{
			t[a[i]]++;
			sum++;
			b[sum]++;
		}
	
		
	}	
	}

	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}

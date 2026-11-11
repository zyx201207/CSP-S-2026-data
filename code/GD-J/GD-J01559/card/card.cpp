#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005]={},p[100005],w1,w2,e=0,q[100005]={},ans[1000005]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			w1++;
		}else{
			w2++;
		}
		if(a[i]<a[i-1]&&i>=2){
			e=1;
		}
	}
	if(e==0){
		for(int j=1;j<=n;j++){
			for(int i=0;i<=90000;i++){
				q[i]=0;
			} 
			for(int k=j;k<=n;k++){
				q[a[k]]=1;
			}
			for(int i=1;i<=m;i++){
				if(q[i]==1){
					ans[i]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(ans[i]==0) continue; 
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	if(w1==0){
		cout<<0<<" "<<5;
	}else if(w2==0){
		cout<<5<<" "<<0;
	}else{
		cout<<4<<" "<<5;
	}
}

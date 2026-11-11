#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int a[N],n,d,c,t;
int calc(int u,int v){
	int lst=u,step=0;
	for(int i=u;i<=v;){
		int sum=0;
		while(sum<=d)sum+=a[i]-a[lst],i++;
		lst=i;
		step++;
	}
	return step;
}
int main(){
	cin>>n;
	for(int i=0;i<(1<<n);i++){
		for(int k=0;k<n;k++){
			if(i&(1<<k))cout<<1<<" ";
			else cout<<0<<" ";
		}
		cout<<"\n";
	}
/*	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int u=1;u<=n;u++){
			for(int v=u+1;v<=n;v++){
				int mn=calc(u,v);
			//	cout<<u<<"->"<<v<<" "<<mn<<"\n";
				
			}
		}
		
	}*/
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int h[1000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	int i=1;
	while(i<=t){
		for(int j=0;j<1000000;j++){
			h[j]=0;
		}
		i++;
		int n,k;cin>>n>>k;
		for(int j=1;j<n;j++){
			int u,v;cin>>u>>v;
			h[abs(u-v)]++;
		}
		int mx=0;
		int kk=0;
		for(int s=0;s<1000000;s++){
			if(h[s]>mx){mx=h[s];kk=s;}
			if(h[s]==mx&&s>kk) kk=s;
		}
		cout<<kk<<"\n";
	}
}

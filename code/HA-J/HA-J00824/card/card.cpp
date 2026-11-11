#include<bits/stdc++.h>
using namespace std;
int n,m,t=0,k=0;
int q_=1,w,u;
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
int s1[n+1];
int ans[n]={0};
for(int i=1;i<=n;i++){
	cin>>s1[i];
}
for(int i=1;i<=n;i++){
	int strck[n+1]={0};
	for(int j=1-k;j<=n;j++){
		w=s1[j];
		t++;
		int qq=1;
		for(int v=1;v<=t;v++){
			if(w==strck[v]){
				for(int e=t-1;e>=v;e--){
					strck[e]=0;
					t--;
				}
			}
			strck[t]=w;
		}
	}
	k++;
	for(int s=1;s<=t;s++){
	if(strck[s]!=0){
	u=strck[s]-1;
	ans[u]+=1;
}
}

for(int c=0;c<n;c++)
	cout<<ans[c]<<" ";
	}


	return 0;
}

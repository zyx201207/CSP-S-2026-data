#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	 freopen("card.out","w",stdout);
	 int n,m;
	 cin>>n>>m;
	 int cards[n+1],time[m+1];
	 for(int i=1;i<=m;i++){
	 	time[i]=0;
	 }
	 for(int i=1;i<=n;i++){
	 	cin>>cards[i];
	 }
	
	 for(int i=1;i<=n;i++){
	 	 vector<int>now(n+1,0);
	 	for(int k=i;k<=n;k++){
		 
	 	for(int j=1;j<=n;j++){
	 		if(now[j]==cards[k]){
	 			for(int l=j;l>=1;l--){
	 				now[l]=0;
				 }
			 }
			 
		 }
		 now.push_back(cards[k]);
		 
		 
	 }
	 for(int o=1;o<=n;o++){
	time[now[o]]++;
	 }
}
for(int i=1;i<=m;i++){
	cout<<time[i]<<" ";
}
}

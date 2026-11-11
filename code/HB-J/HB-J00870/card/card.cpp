#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n,m;
int arr[200010];
int ans[200010];


bool suf_eo[5050][5050];

void solve(){ 
	bool flagA=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		if(arr[i]<arr[i-1])flagA=0;
	}
	
	
	
	if(n<=800){
		
		int cards[800];
		for(int i=1;i<=n;i++){
			memset(cards,0,sizeof cards);
			for(int j=i;j<=n;j++){
				for(int k=j;k>=i;k--){
					if(cards[k]==arr[j]){
						for(int l=k;l<=j;l++){
							cards[l]=0;
						}
					}
				}
				cards[j]=arr[j];
				
			}
			
			for(int i=1;i<=n;i++){
				if(cards[i]!=0){
					ans[cards[i]]++;
				}
			}
		}
		
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	}
	else if(m==2){
		ll flag=0;
		for(int i=1;i<=n;i++){
			if(arr[i]!=arr[i-1]){
				flag=i;
			}
		}
		
		cout<<flag<<endl;
		
		if(flag%2==1)cout<<(flag+1)/2<<" ";
		else cout<<flag/2<<" ";
		
		if((n-flag+1)%2==0)cout<<(n-flag+1)/2;
		else {cout<<(n-flag)/2;}
	}
	else{
		for(int i=1;i<=n;i++){
			int cards[5010];
			for(int j=i;j<=n;j++){
				cards[j]=arr[j];
				if(cards[j]==cards[j-1]){
					cards[j]=cards[j-1]=0;
				}
			}
			
			for(int j=i;j<=n;j++){
				
				ans[cards[j]]++;
				
			}
		}
		
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		
	}
	
}
int main(){
	 freopen("card.in","r",stdin);
	 freopen("card.out","w",stdout);
	
    //ios::sync_with_stdio(false);
	//cin.tie(nullptr);cout.tie(nullptr);
	
	solve();
	
	//fclose(stdin);
   	//fclose(stdout);
	return 0;
}











// 7 11:12 -- wcqk HB-J00870

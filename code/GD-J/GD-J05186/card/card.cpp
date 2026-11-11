#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,card[100005],num[100005],ans[100005];
	cin>>n>>m;
	int l=0;
	memset(card,0,sizeof(card));
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	if(n==1){
		if(card[1]==1){
			cout<<"1";
			return 0;
		}
		else{
			cout<<"0";
			return 0;
		}
	}
	for(int i=1;i<=n+1;i++){
		memset(num,-1,sizeof(num));
		int xx=0;
		for(int j=i+l;j<=n;j++){
			num[j]=card[j];
			xx=j;
			for(int h=1;h<j;h++){
				if(num[h]==num[j]){
					for(int a=h;a<j;a++){
						num[a]=-1;
					}
				}
			}
			l++;
			
		}
		
		
		for(int h=1;h<=xx;h++){
				if (num[h]!=-1){
					ans[num[h]]++;
				}
		}
		l=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

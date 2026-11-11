#include<iostream>
using namespace std;
int n,c,card[7],right_[7],ans[5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool bol[7];
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>card[i];
		bol[i]=true;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			right_[j]=0;
		}
		int p=1;
		for(int j=i;j<=n;j++){
			bool falg=true;
			for(int x=1;x<=n;x++){
				if(right_[x]==card[j]){
					falg=false;
					break;
				}
			}
			if(falg){
				right_[p]=card[j];
				p++;
			}else{
				p=1;
				right_[p]=card[j];
			}
		}
		for(int j=1;j<=c;j++){
			for(int x=1;x<p;x++){
				if(right_[x]==j && bol[j]){
					ans[j]++;
					break;
				}
				if(x==p-1){
					bol[j]=false;
				}
			}
		}
	}
	for(int i=1;i<=c;i++){
		cout<<ans[i]<<" ";
	}
	return 0;	
} 

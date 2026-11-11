#include<bits/stdc++.h>
using namespace std;
const int maxn=500090,maxm=300090;bool fa=1;
int n,m,pai[maxn],last[maxm],desk[maxn],cnt[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>pai[i];
		if(i>0){
			if(pai[i]<pai[i-1]){
				fa=0;
			}
		}
	}
	for(int i=0;i<n;i++){
		int l=0;
		for(int j=0;j<maxm;j++){
			last[j]=-1;
		}
		for(int j=0;j<maxn;j++){
		    desk[j]=0;
		}
		for(int j=i;j<n;j++){
			if(fa==1){
				if(l>0){
					if(desk[l-1]==pai[i]){
						desk[l-1]=pai[i];
					}
					else{
						desk[l++]=pai[i];
					}
				}
				else{
					desk[l++]=pai[j];	
				}
			}
			if(last[pai[j]]==-1){
				desk[l]=pai[j];
				last[pai[j]]=l++;
			}
			else{
				int k=last[pai[j]]+1;
				for(;k<l;k++){
					last[desk[k]]=-1;
					desk[k]=0;
				}
				l=k;
			}
		}
		for(int j=0;j<l;j++){
			cnt[desk[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}

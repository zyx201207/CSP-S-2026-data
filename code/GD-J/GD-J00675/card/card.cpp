#include<bits/stdc++.h>
using namespace std;
long long n,m,card[500005];
long long tong[500005],game[500005],l,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>card[i];
	}
	for(long long i=0;i<n;i++){
		l=0;
		memset(game,0,sizeof(game));
		for(long long j=i;j<n;j++){
			memset(tong,-1,sizeof(tong));
			for(long long p=0;p<=l;p++){
				tong[game[p]]=p;
				
			}
//			cout<<card[j]<<' '<<tong[card[j]]<<' ';
			if(tong[card[j]]==-1){
				game[l]=card[j];
				tong[card[j]]=l;
//				cout<<tong[card[j]]<<'p';
				l++;
			}else{
				int l1343=l;
				for(long long k=tong[card[j]]+1;k<=l1343;k++){
					tong[card[k]]=-1;
					game[k]=0;
					l--;
				}
				game[l]=card[j];
				tong[card[j]]=l;
//				cout<<tong[card[j]]<<'p';
				l++;
			}
//			for(int p=0;p<l;p++){
//				cout<<game[p]<<' ';
//			}
//			cout<<endl;
//			cout<<endl;
			

		}
//		cout<<endl<<endl;
//		cout<<endl<<endl;
//		cout<<endl<<endl;
//		cout<<endl<<endl;
		for(long long j=0;j<l;j++){
			ans[game[j]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

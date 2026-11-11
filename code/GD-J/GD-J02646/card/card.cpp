#include<bits/stdc++.h>
using namespace std;

const int N=500005,M=300005;
int n,m,cnt;
int arr[N],cur[2*N],last_id[M],ans[M];
void play(int x){
	for(int i=x;i<=n;i++){
		if(last_id[arr[i]]==-1){
			cur[++cnt]=arr[i];
			last_id[arr[i]]=cnt;
		}
		else{
			int sum=last_id[arr[i]];
			for(int j=sum;j<=cnt;j++){
				last_id[cur[j]]=-1;
				cur[j]=0;
			}
			cnt=sum;
			cur[cnt]=arr[i];
			last_id[arr[i]]=cnt;
		}
	}
	for(int i=1;i<=cnt;i++){
		ans[cur[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		last_id[i]=-1;
	}
	for(int i=1;i<=n;i++){
		play(i);
		cnt=0;
		for(int i=1;i<=n;i++){
			cur[i]=0;
			last_id[i]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

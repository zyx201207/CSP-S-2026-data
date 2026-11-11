#include<bits/stdc++.h>

using namespace std;
int cnt[300010];
int n,m;
int card[500010];
int cun[500100];
void lun(int p){
	for(int i=p;i<=n;i++){
		cun[i]=card[i];
	}
	int k=cun[n];
	for(int i=n;i>=p;i--){
		for(int j=n-1;j>=p;j--){
			if(k==cnt[j]){
				for(int z=i-1;z>=j;z--) cun[z]=0;
				int qw=j-1;
				if(qw<p) break;
				else i=qw;
				break;
			}
		}
		k=cun[i];
	}
	for(int i=p;i<=n;i++){
		if(cun[i]!=0) cnt[cun[i]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>card[i];
	for(int i=1;i<=n;i++){
		lun(i);
	}
	cnt[1]--;
	cnt[2]--;
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<endl;
	}
	return 0;
}

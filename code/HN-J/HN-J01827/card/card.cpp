#include <bits/stdc++.h>
using namespace std;
int incd(const vector<int>& cd,const int& k){
	for(int i=0;i<cd.size();i++){
		if(cd[i]==k) return i;
	}
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		if((n+1)>>1) printf("1 \n");
		else printf("0 \n");
		return 0;
	}
	
	vector<int> cr(n+1);//牌堆 
	vector<int> cnt(m+1,0);//结果 
	for(int i=0;i<n;i++){
		cin>>cr[i];
	}
	for(int i=0;i<n;i++){
		//printf("1f ");
		vector<int> cd(n+1,-1);//桌面 
		int tp=-1;
		vector<int> ct(m+1,-1);//每个点数的位置 
		for(int j=i;j<=n;j++){
			//printf("2f ");
			if(ct[cr[j]]==-1){//没有放过 
				//printf("1l ");
				tp++;
				cd[tp]=cr[j];
				ct[cr[j]]=tp;
			}
			else{//有 
				//printf("2l ");
				for(int i=tp;i>ct[cr[j]];i--){
					ct[cr[i]]=-1;
				}
				tp=ct[cr[j]];
				cd[tp]=cr[j];
			}
			for(int i=0;i<=tp;i++){
				//printf("d%d ",cd[i]);
			}
		}
		for(int i=0;i<tp;i++){
			//printf("1p ");
			cnt[cd[i]]++;
			//printf("2p ");
		}
	}
	for(int i=1;i<=m;i++){
		//printf("1o ");
		printf("%d ",cnt[i]);
	}
	return 0;
}

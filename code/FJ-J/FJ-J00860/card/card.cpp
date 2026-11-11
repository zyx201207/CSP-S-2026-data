#include<bits/stdc++.h>
using namespace std;
long long nzyl,mzzl,arzy[500005],wazzl[300005];
stack<long long>q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>nzyl>>mzzl;
	for(int i=1;i<=nzyl;i++){
		cin>>arzy[i];
	}
	for(long long i=1;i<=nzyl;i++){
		long long fzyx[300005];
		for(long long j=i;j<=nzyl;j++){
			if(fzyx[arzy[i]]<1){
				q.push(arzy[i]);
				fzyx[q.top()]++;
			}else{
				while(fzyx[arzy[i]]>=1){
					fzyx[q.top()]--;
					q.pop();
				}
			}
		}
		for(long long j=1;j<=mzzl;j++){
			wazzl[fzyx[i]]++;
		}
		
	}
	for(long long j=1;j<=mzzl;j++){
		cout<<wazzl[j]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N_=5e5+10;
int n_,m_;
int a_[N_],vis_[N_],cnt_[N_],cnt_2[N_],b_2[N_],b_[N_];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n_>>m_;
    for(int i=1;i<=n_;i++){
    	cin>>a_[i];
	}
	vis_[a_[n_]]=n_;
	for(int i=n_;i>=1;i--){
		if(b_[a_[i]]==1){
			cnt_[a_[i]]=i;
		}
		b_[a_[i]]++;
	}
	for(int i=1;i<=n_;i++){
		if(b_2[a_[i]]==0 and b_[a_[i]]!=1){
			cnt_2[a_[i]]=i;
		}
		b_2[a_[i]]++;
	}
	for(int i=n_-1;i>=1;i--){
		if(vis_[a_[i]]==0) {
		    if(cnt_2[a_[i+1]]>cnt_2[a_[i]]){
		    	vis_[a_[i]]=i-cnt_2[a_[i+1]]+cnt_2[a_[i]];
			}else{
				vis_[a_[i]]=i-cnt_[a_[i+1]];
			}
		}
	}
	for(int i=1;i<=m_;i++) cout<<vis_[i]<<' ';
	return 0;
} 

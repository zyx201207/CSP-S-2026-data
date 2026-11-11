#include<bits/stdc++.h>
using namespace std;
const int N_=2e5+10;
struct P{
	long long l_;
	char c_;
};
int n_;
P a_[N_];
long long pre_[N_],suf_[N_];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n_;
    for(int i=1;i<=n_;i++){
    	cin>>a_[i].l_>>a_[i].c_;
		pre_[i]=pre_[i-1]+a_[i].l_; 
	}
	for(int i=1;i<=n_;i++){
		suf_[i]=pre_[n_]-pre_[i-1];
	}
	int pre_idx=1,suf_idx=n_;
	long long cnt=0;
	while(pre_idx<suf_idx){
		if(pre_[pre_idx]>=suf_[suf_idx]){
			if(a_[pre_idx].c_!=a_[suf_idx].c_){
				cnt+=a_[suf_idx].l_;	
				a_[pre_idx].l_-=a_[suf_idx].l_;
			}
			else{
				a_[pre_idx].l_-=a_[suf_idx].l_;
			}
			suf_idx--; 
		}
		else{
			if(a_[pre_idx].c_!=a_[suf_idx].c_){
				cnt+=a_[pre_idx].l_;
				a_[suf_idx].l_-=a_[pre_idx].l_;	
			}
			else {
				a_[suf_idx].l_-=a_[pre_idx].l_;	
			}
			pre_idx++; 
		}
	}
	cout<<cnt;
	return 0;
} 

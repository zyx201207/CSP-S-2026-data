#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[200005];
struct bt{
	int index[200005];
	int cnt;
}bts[32];
int usable[32];
int hx[200005];
bool abandon[200005];
int hx_cnt=0,abandon_cnt=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		for(int j=0;j<32;j++){
			if(num[i]&(1<<j)){
				bts[j].cnt++;
				bts[j].index[bts[j].cnt]=num[i];
			}
		}
	}
	if(m==1){
		cout<<*max_element(num+1,num+1+n);
		return 0;
	}
	for(int i=31;i>=0;i--){
		if(m>bts[i].cnt){
//			cerr<<"ip bt"<<i<<endl;
			continue;
		}
		else{
//				cerr<<"st bt"<<i<<endl;
				for(int j=1;j<=bts[i].cnt;j++){
					hx_cnt++;
					hx[hx_cnt]=bts[i].index[j];
					for(int u=0;u<32;u++){
						usable[u]+=(hx[hx_cnt]&(1<<u));
					}
//					cerr<<bts[i].index[j]<<" is in hx"<<endl;
				}
				for(int u=i-1;u>=0;u--){
//					cerr<<"now bt"<<u<<" "<<usable[u]<<" usable"<<endl;
					if(usable[u]<m){
						continue;
					}
					int lst_abandon[200005]={0};
					int lst_abd_cnt=0;
					for(int j=1;j<=hx_cnt;j++){
						if(abandon[j]) continue;
						if(!(hx[j] & (1<<u))){
							abandon[j]=1;
							abandon_cnt++;
							lst_abd_cnt++;
							lst_abandon[lst_abd_cnt]=j;
							for(int p=0;p<u;p++){
								usable[p]-=(hx[j]&(1<<p));
							}
//							cerr<<"abandon "<<hx[j]<<endl;
						}
					}
//					cerr<<"cnt "<<hx_cnt-abandon_cnt<<endl;
					if(hx_cnt-abandon_cnt<m){
						for(int i=1;i<=lst_abd_cnt;i++){
							abandon_cnt--;
							abandon[lst_abandon[i]]=0;
						}
					}
				}
				break;
		}
	}
	if(hx_cnt-abandon_cnt==0){
		cout<<0;
	}else{
		int ans=INT_MAX;
		for(int i=1;i<=hx_cnt;i++){
			if(abandon[i])continue;
//			cerr<<"fin choose "<<hx[i]<<endl; 
			ans&=hx[i];
		}
		cout<<ans;
	}
}

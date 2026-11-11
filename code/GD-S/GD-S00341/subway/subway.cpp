#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+10;
struct node{
	int n,w;
};
vector<node> a[250];
ll c,n,m,d,q;
ll w_[N];
ll b[N];
int main(){
	//只拿1~3的分 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdin);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w_[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(ll j=1;j<=k;j++){
			ll ta,tb;
			cin>>ta>>tb;
			node tp;tp.n=ta;tp.w=tb;
			b[i]++;
			a[i].push_back(tp);
		}
	}
	for(ll i=1;i<=q;i++){
		ll l,r;
		cin>>l>>r;
		ll min_=0x3f;
		for(ll j=1;j<=3;j++){ //第一条路线
			for(ll k=0;k<b[j];k++){
				if(a[j][k].n==l){
					ll ans=a[j][k].w+w_[l];
					for(ll k1=0;k1<b[j];k1++){ //直达 
						if(a[j][k1].n==r){
							min_=min(min_,ans+a[j][k1].w+w_[r]);
							break; 
						}
					}
					for(ll k1=1;k1<=3;k1++){ //转车,第二条路线 
						if(k1==j) continue;
						for(ll k2=0;k2<b[j];k2++){ //第1条路线的战点 
							for(ll k3=0;k3<b[k1];k3++){ //第2条路线的战点 
								if(a[j][k2].n==a[k1][k3].n){ //转车点 
 									for(ll k4=0;k4<b[k1];k4++){ //终点 
				 						if(a[k1][k4].n==r){
											min_=min(min_,ans+a[k1][k3].w+a[j][k2].w+a[k1][k4].w+w_[r]);
											break;
										}
										
									}
									for(ll k5=1;k5<=3;k5++){ //转车,第3条路线 
										if(k5==j||k5==k1) continue;
										for(ll k6=0;k6<b[k1];k6++){ //第2条路线的战点 
											for(ll k7=0;k7<b[k5];k7++){ //第3条路线的战点 
												if(a[k1][k6].n==a[k5][k7].n){ //转车点 
				 									for(ll k8=0;k8<b[k5];k8++){ //终点 
								 						if(a[k5][k8].n==r){
															min_=min(min_,ans+a[j][k2].w+a[k1][k3].w+a[k1][k6].w+a[k5][k7].w+a[k5][k8].w+w_[r]); //第一次转车+第二次转车 
															break;
														}
													
													}
													
												}
											}
										}
									
								}
								}
							}
						}
						
					}
					continue;
				}
			}
		}
		cout<<min_<<endl;
	}
	
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
struct S{
	int sum;
	char c;
	void read(){cin>>sum>>c;};
};
vector<S> vec;
int tot,ans;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	vec.assign(n+1,{0,0});
	int pos=0;
	for(int i=1;i<=n;i++){
		vec[++pos].read();
		tot+=vec[pos].sum;
		while(vec[pos].c==vec[pos-1].c){
			vec[pos-1].sum+=vec[pos].sum;
			pos--;
		}
	}
	int kkk=tot/2;
	int ps;
	vector<S> tmp;
	for(int i=1;;i++){
		if(vec[i].sum<kkk){
			tmp.push_back(vec[i]);
			kkk-=vec[i].sum;
		}
		if(vec[i].sum>=kkk){
			tmp.push_back({kkk,vec[i].c});
			vec[i].sum-=kkk;
			ps=i;
			break;
		}
	}
	int i=ps,j=0;
	reverse(tmp.begin(),tmp.end());
	while(i<=n&&j<ps){
		if(tmp[j].c!=vec[i].c){
			if(vec[i].sum>=tmp[j].sum){
				ans+=tmp[j].sum,vec[i].sum-=tmp[j].sum,j++;
			}
			else{
				ans+=vec[i].sum,tmp[i].sum-=vec[i].sum,i++;
			}
		}
		else{
			if(vec[i].sum>=tmp[j].sum){
				vec[i].sum-=tmp[j].sum,j++;
			}
			else{
				tmp[i].sum-=vec[i].sum,i++;
			}
		}
	}
	cout<<ans;
	return 0;
} 

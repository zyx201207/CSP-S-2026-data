#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int n,m,a[N];
map<int,int> id;int cnt,tim[N],lst[N];
vector<int> num;int n1[N];

bool ysnb=1;
int delta;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!id.count(a[i])){
			id[a[i]]=++cnt;
			num.push_back(a[i]);
			n1[cnt]=a[i];
		}
		tim[id[a[i]]]++;
		if(tim[id[a[i]]]>1) ysnb=0;
	}
	int ans=1;
	sort(num.rbegin(),num.rend());
	
	for(int i=1;i<num.size();i++){
		if(i==1) delta=num[0]-num[1];
		else if(num[i-1]-num[i]!=delta) ysnb=0;
	}
	if(ysnb){
		int rans=0;
		for(ans;ans*(ans-1)/2*delta<=m&&ans<=n;ans++){
			rans=ans;
		}
		cout<<rans;
		return 0;
	}
	
	int lst_=0;
	for(auto i:num){
		if(lst_!=0){
			lst[lst_]=id[i];
		}
		lst_=id[i];
	}
	for(auto i:num){
		int now=tim[id[i]],nowm=m;
		int j=lst[id[i]];
		while(nowm>=i-n1[j]&&j){
			int t=min(tim[j],nowm/(i-n1[j]));
			nowm-=t*(i-n1[j]);
			now+=t;
			j=lst[j];
		}
		ans=max(ans,now);
	}
	cout<<ans;
	
	return 0;
}


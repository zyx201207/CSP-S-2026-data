#include<bits/stdc++.h>
#define _ti_mu (string)("crystal")
using namespace std;
#define LS_ //表示序号、内容离散化 
#define ORI_
#define tiaoshi 0
#define t_ if(tiaoshi)
using ll = long long;using vi = vector<int>;
using pii = pair<int,int>;using vll = vector<ll>;
ORI_ vll _a;//排序后的原始值
LS_  vi a;//离散化后的值
map<ll,int> ori2ls;
map<int,ll> ls2ori;
//离散化前后的对应关系 
LS_ int cnt[500005];
//（离散化后的）各数字数目 

int daijia(LS_ int from,LS_ int to){
	assert(from<=to);//daijia check
	ll ori1 = ls2ori[from],ori2 = ls2ori[to];
	ll dj = ori2-ori1;
	return dj;
} 

int query(LS_ int x,int m){
	int pos_first = 0;
	for(int i = 1;i<x;i++) pos_first+=cnt[i];
	//cout<<pos_first<<endl;
	
	int cost = 0;
	int res = cnt[x];//已有的合格的部分。 
	int pos = pos_first-1;
	while(pos>=0){
		ll _cos = daijia(a[pos],x);
		if(cost+_cos>m){
			break;
		}
		else{
			cost+=_cos;
			pos--;
			res++;
		}
	}
	return res;
}
int query_v2(LS_ int x,int m){
	
	int cost = 0;
	int res = cnt[x];//已有的合格的部分。 
	int num_ls = x-1;
	while(num_ls>0){
		ll each_cost = daijia(num_ls,x);
		int max_num = cnt[num_ls];
		int usg = max(min({static_cast<ll>(max_num),
			(static_cast<ll>(m-cost)/each_cost)}),(ll)0);
			
		cost+=usg*each_cost;
		res+=usg;
		if(usg==cnt[num_ls]){
			num_ls--;
		}
		else{
			break;
		}
	}
	return res;
}
bool is_dcsl(int n){
	int gc = _a[1]-_a[0];
	for(int i = 1;i<n;i++){
		if(_a[i]-_a[i-1]!=gc) return 0;
	}
	return 1;
}
bool is_tp2(int n){
	for(int i = 0;i<n;i++){
		if(_a[i]!=i+1) return 0;
	}
	return 1;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	freopen((_ti_mu+".in").c_str(),"r",stdin);
	freopen((_ti_mu+".out").c_str(),"w",stdout);
	//froepen ??
	int n,m;cin>>n>>m;
	for(int i = 1;i<=n;i++){
		ll x;cin>>x;
		_a.push_back(x);
	}
	sort(_a.begin(),_a.end());
	
	{
		if(n>5000&&is_dcsl(n)){
			t_ cout<<"tp1 on\n";
			int gc = _a[1]-_a[0];//公差
			m = (ll)m/(ll)gc;
			int jian = _a[0];//统一到零 
			for(int i = 0;i<n;i++){
				_a[i]-=jian;
				_a[i]/=gc;
			}
		}//tp1: for test 16~18
		if(n>5000&&is_tp2(n)){
			t_ cout<<"tp2 on\n";
			int r = 0;
			while(m>=r*(r+1)/2) r++;
			int ans = r;
			cout<<ans<<endl;
			return 0;
		}//tp2: for test 13~15
	}
	
	
	t_ for(ll i : _a) cout<<i<<" ";
	t_ cout<<"\nn="<<n<<" m="<<m<<endl;
	a.assign(n+10,0);
	
	{
		ll now_num = _a[0],ls_num = 1;
		ori2ls[_a[0]] = 1;
		ls2ori[1] = _a[0];
		for(int i = 0;i<(signed)_a.size();i++){
			if(now_num==_a[i]){
				a[i] = ls_num;
			}
			else{
				now_num = _a[i];
				ls_num++;
				ori2ls[now_num] = ls_num;
				ls2ori[ls_num] = now_num;
				
				a[i] = ls_num;
			}
		}
		for(int i = 0;i<n;i++){
			ll var = a[i];
			cnt[var]++;
		}
	}//离散化 统计。
	t_ {
		for(int i = 0;i<n;i++){
			printf("i=%3d num=%3lld->%3d cnt=%3d\n",
				i,_a[i],a[i],cnt[a[i]]);
		}
	}
	//t_ cout<<"chk:daijia "<<daijia(1,4)<<endl;
	int ans = 0;
	int max_ls_num = a[n-1];
	for(int i = 1;i<=max_ls_num;i++){
		/*int q1 = query(i,m),q2 = query_v2(i,m);
		ans = max(ans,q1);
		if(q1!=q2){
			printf("i=%d q1=%d q2=%d\n",i,q1,q2);
		}*/
		int qry;
		if(n<=5000) qry = query(i,m);
		else qry = query_v2(i,m);
		ans = max(ans,qry);
	}
	cout<<ans<<endl;
	//query(4,m);
	return 0;
}
/*
zhe shi xixifu gei de zui liang xing de ti.
*/

//string
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,ans;

struct stu{
	char c;
	int len,l,r;
};

vector <stu> v;

//void debug(){
//	for (int i = 0;i < v.size();i ++){
//		cout<<v[i].c<<' '<<v[i].len<<' '<<v[i].l<<' '<<v[i].r<<endl;
//	}
//}

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for (int i = 1;i <= n;i ++){
		int a;char tmp;
//		cin>>a>>tmp;
		scanf("%lld",&a);
		cin>>tmp;
		v.push_back({tmp,a,0,0});
		if (v.size() > 1){
			v[v.size() - 1].l = v[v.size() - 2].r + 1;
		}
		v[v.size() - 1].r = v[v.size() - 1].l + a - 1;
	}
	int le = 0,ri = v.size() - 1,s = v.size();
	while (s > 0){
		int tmp = min(v[le].len,v[ri].len);
		v[le].len -= tmp;
		v[ri].len -= tmp;
		if (v[le].c != v[ri].c){
			ans += tmp;
		}
		if (v[le].len <= 0){
			le ++;
			s --;
		}
		if (v[ri].len <= 0){
			ri --;
			s --;
		}
//		debug();
	}
	printf("%lld",ans);
	return 0;
}

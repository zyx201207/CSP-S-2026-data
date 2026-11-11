#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
/*
根本没有这样的题

1 2 5 3 6 5 4 7 2 3 2 4 2
3 6 0 3
2 8 0 2
4 10 3 4
8 13 4 8
牛逼这把给了 


每个区间在他的所有限制用不了的时候他就能用。。。
但是只有6分钟了，回档了，调不出来
假解就假解吧，万一呢 
ORZ ORZ ORZ
*/
int n,m;
int a[MAXN];
int p[MAXN]; //计数 
int f[MAXN]; //前面最后一个相同
struct le{
	int l,r; //起终
	int s,e; //启用时间 截至时间 对于没有交叉的区间s = 0 e = l;
	//vector<int> rel;   最后挣扎 
}ln[MAXN]; 
bool cmp(le a,le b){
	return a.r < b.r;
}
int cnt = 0;
int col[MAXN];
int cl[MAXN];
int ans[MAXN];
void solve(int x){
	
	fill(col+1,col+n+1,0);
	fill(cl+1,cl+n+1,0);
	vector<le> lns;
	
	for(int j = 1;j <= cnt;j ++){
		if(ln[j].e >= x && ln[j].s <= x){
			lns.push_back(ln[j]);
	 }
	}
	for(int j = 0;j < (int)lns.size();j ++){
		col[lns[j].l] = 1; col[lns[j].r] = -1;
	} 
	
	for(int j = 1;j <= n;j ++){
		cl[j] = cl[j-1] + col[j];
		//cout<<cl[j]<<" ";
		if(cl[j]== 0 && j >= x){
			ans[a[j]] ++;
		}
	}
	//cout<<'\n';
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
		if(p[a[i]]){
			f[i] = p[a[i]];
		} 
		p[a[i]] = i;
	}
	int k = 0;
	for(int i = 1;i <= n;i ++){
		if(f[i]){
			ln[++cnt].l = f[i];ln[cnt].r = i;
			ln[cnt].e = ln[cnt].l;
		}
	}
	sort(ln+1,ln+cnt+1,cmp);
    //666这咋算
	for(int i = 1;i <= cnt;i ++){
		for(int j = 1;j < i;j ++){
			if(ln[i].l < ln[j].r && ln[i].l > ln[j].l ){
				ln[i].s = ln[j].l;
			}
		}
	}
	//cout<<cnt<<'\n';
	//for(int i = 1;i <= cnt;i ++){
	//cout<<ln[i].s<<" "<<ln[i].e<<" "<<ln[i].l<<" "<<ln[i].r<<'\n';
	//}
	//劲爆模拟 
	for(int i = 1;i <= n;i ++){
		solve(i);
		
	}
	for(int i = 1;i <= m;i ++){
		cout<<ans[i]<<" ";
	}
}
/*
重操旧业了
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen
bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h
 bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h
  bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h
   bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h
    bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h
     bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h
      bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h bits\stdc++.h
      //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen 
//freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen //freopen
*/ 

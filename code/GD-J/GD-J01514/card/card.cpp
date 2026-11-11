#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
	}
	stack<int>s;
	vector<bool>h(m);
	vector<int>out(m);
	for(int i=0;i<n;i++){
		for(int i=0;i<m;i++)h[i]=0;//i haven't write this before,but it is broken!
		//That means almost clear can't do it!
		for(int j=i;j<n;j++){
			if(h[a[j]]){
				//have sth in the stack!
				while(s.top()!=a[j]&&(!s.empty())){
					h[s.top()]=0;
					s.pop();
				}
				if(s.top()==a[j])s.pop();
			}s.push(a[j]);
			h[a[j]]=1;
		}
		while(!s.empty()){
			out[s.top()]++;
			s.pop();
		}
	}
	for(int i=0;i<m;i++){
		cout<<out[i]<<" ";
	}
	return 0;
}
//kai huo che?!
//what's the matter for it?
/*
have the kard of [sth]?
(1).the kard has only one in the desk;
(2).the kard have two or more,but some of them was been deleted.
maybe i need to move it by myself.
but......???
Ah!
i need to do that in another way,
->add it from right to left.
keep a hash to check which kard is loaded.
if this kard is loaded,but i load another,this one should be unload,and all of them will delete.
->1 2 3 1 2 3?
3:done.
0 0 1
2 3:done.
0 1 2
1 2 3:done.
1 2 3
3 1 2 3:'3'deleted.what?
2 3 4
2 3 1 2 3:'2 3 1'deleted!that means the last 2 have effect on it!
2 4 5
1 2 3 1 2 3:'1 2 3'deleted,and what?it killed the effect on 2!
3 5 6
i must to confused some points.
*/

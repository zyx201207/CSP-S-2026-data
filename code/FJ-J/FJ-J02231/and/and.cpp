#include<bits/stdc++.h>
using namespace std;
int n,m,t=0,y=0;
struct qwe{
	int yl,bl;
}ns[200005];
bool wwe(qwe x,qwe y){
	if(x.yl>y.yl||(x.yl==y.yl&&x.bl>=y.bl)){
		return true;
	}
	else{
		return false;
	}
}
int wer(int x){
	int js=0;
	while(x>0){
		if(x%2==1){
			js++;
		}
		x=x/2;
	}
	return js;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int z=1;z<=n;z+=1){
		cin>>ns[z].bl;
		ns[z].yl=wer(ns[z].bl);
	}
	sort(ns+1,ns+n+1,wwe);
	t=ns[1].bl;
	for(int z=2;z<=m;z+=1){
		t=t&ns[z].bl;
		//cout<<t
	}
	cout<<t;
	return 0;
}

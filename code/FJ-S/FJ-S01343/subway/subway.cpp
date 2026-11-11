#include<bits/stdc++.h>
using namespace std;
struct ints{
	int x,y;	
};
vector<ints> a[10007],b[10007]; 
int T,n,n2,m,d,q,bk[1007];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>T>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>bk[i];//返回站台的时间 
	for(int i=1;i<=n;i++){
		cin>>n2;
		int x,y;ints ls;
		for(int j=1;j<=n2;j++){
			cin>>x>>ls.y;
			ls.x=i,ls.y+=bk[i];
			a[x].push_back(ls);
			ls.x=x;
			b[i].push_back(ls);
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=0;i<b[x].size();i++){
			if(bx[1].a==i) i=
		}
		
	}
	
	return 0;
}
//只管换线的时间
//返回的时间相同
//不明白：d是干什么的 


#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=5e5+5;
int c,n,m,d,q,k;
int w[N],Walk;
struct T{
	int line,id,IN;
}t[N];
bool cmp(T a,T b){
	if(a.id==b.id){
		if(a.line==b.line){
			return a.IN<b.IN;
		} 
		return a.line<b.line;
	}
	return a.id<b.id;
	
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i){
		cin>>w[i];
	}
	c=0;
	for(int i=1;i<=n;++i){//line
		cin>>k;
		for(int j=1;j<=k;++j){//stations
			int sta,IN;
			cin>>sta>>IN;
			c++;
			t[c].id=sta;
			t[c].line=i;
			t[c].IN=IN;
		}
	}
	sort(t+1,t+c+1,cmp);
	for(int i=1;i<=q;++i){
		int bst,est,BLz,ELz,SL;
		vector<int> BL,EL;
		cin>>bst>>est;
//		cout<<bst<<' '<<est<<endl;
		Walk+=w[bst]+w[est];
//		cout<<w[bst]<<' '<<w[est]<<endl;
		for(int j=1;j<=c;++j){
			if(t[j].id==bst){
				BL.push_back(t[j].line);
			}
			if(t[j].id==est){
				EL.push_back(t[j].line);
			}
		}
		for(int j=1;j<=EL.size();++j){
			for(int k=1;k<=BL.size();++k){
				if(EL[j]==BL[j]){
					BLz=EL[j];
					ELz=EL[j];
					SL=BLz;
				}
			}
		}
 		if(SL==0){
 			for(int j=1;j<c;++j){
				if(t[j].id==t[j+1].id&&((BLz==t[j].line||ELz==t[j+1].line)||(ELz==t[j].line||BLz==t[j+1].line))){
					Walk+=t[j].IN+t[j+1].IN;
				}
			}
		}
		for(int j=1;j<=c;++j){
			if(t[j].id==bst&&t[j].line==SL){
				Walk+=t[j].IN;
			}
			if(t[j].id==est&&t[j].line==SL){
				Walk+=t[j].IN;
			}
		}
		
		cout<<Walk<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 2
1 3
*/

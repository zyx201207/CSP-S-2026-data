#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

struct aa{
	int x,y;
}b[500010];

int n,m,t;
int a[500010];
int tong[500010];
int la[500010];
int mn[500010];
int v[500010];
priority_queue<pair<int,int> >q;
//int tr[2000010];
long long s[500010];

//void add(int x,int y,int f,int l,int s){
//	if(x==y){
//		tr[f]+=s;
//		return;
//	}
//	int mi=(x+y)>>1;
//	if(mi>=l)add(x,mi,f*2,l,s);
//	if(mi<l)add(mi+1,y,f*2+1,l,s);
//	tr[f]=tr[f*2]+tr[f*2+1];
//}
//
//int find_max(int x,int y,int f){
//	if(x==y){
//		return x;
//	}
//	int mi=(x+y)/2;
//	if(tr[f*2+1])return find_max(mi+1,y,f*2+1);
//	else return find_max(x,mi,f*2);
//}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;++i)mn[i]=1e9;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(tong[a[i]]){
			la[i]=tong[a[i]];
			b[++t]={tong[a[i]],i};
		}
		tong[a[i]]=i;
	}
	if(n<=5000){
		stack<int>st;
		for(int i=1;i<=n;++i){
			while(!st.empty())st.pop();
			for(int j=1;j<=m;++j)v[j]=0;
			for(int j=i;j<=n;++j){
				if(v[a[j]]){
					while(!st.empty()&&v[a[j]]){
						--v[st.top()];
						st.pop();
					}
				}
				v[a[j]]=1;
				st.push(a[j]);
			}
//			if(st.empty())cout<<-1;
//			cout<<i<<endl;
			for(int j=1;j<=m;++j){
//				cout<<v[j]<<" ";
				if(v[j])++s[j];
			}
//			cout<<endl;
		}
		for(int i=1;i<=m;++i){
			cout<<s[i]<<" ";
		}
		return 0;
	} 
	sort(b+1,b+t+1,[](aa x,aa y){return x.y<y.y;});
	int nwt=t;
	for(int i=n;i>=1;--i){
		while(!q.empty()&&q.top().first>=i){
			q.pop();
		}
		if(i<mn[a[i]]){
//			cout<<i<<" "<<mn[a[i]]<<endl;
			if(q.size()){
//				cout<<i<<" "<<q.top().first<<endl;
				s[a[i]]+=i-q.top().first;
				mn[a[i]]=q.top().first+1; 	
			}else{
//				cout<<111;
				s[a[i]]+=i;
				mn[a[i]]=1;
			}
//			cout<<mn[a[i]]<<endl;
		}
		while(b[nwt].y>=i&&nwt>=1){
			q.push({b[nwt].x,b[nwt].y});
			--nwt;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<s[i]<<" ";
	} 
	return 0;
}
/*
4 3
1 2 1 3
10 3
3 1 2 1 3 2 3 1 2 1
6 3
3 2 1 2 1 3
*/

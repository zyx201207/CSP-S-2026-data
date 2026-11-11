#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ll long long
#define pb push_back
#define fir first
#define sec second
const int N=5e5+7,M=3e5+7;
int a[N],lst[M],pre[M],n,m,Len,len,ans[N],v[N];
vector<int> E[M];
struct node{
	int x,id;
}Pre[M],Lst[N];
bool cmp(node x,node y){
	return x.id<y.id;
}
bool Cmp(node x,node y){
	return x.id>y.id;
}
int erf(int x,int mid){
	int LEN=0,l=1,r=E[mid].size();
	int ANS=0;
	for(auto it:E[mid]){
		v[++LEN]=it;
	}
	while(l<r){
		int Mid=(l+r)/2;
		if(v[Mid]<x){
			ANS=Mid;
			l=Mid+1;
		}else{
			r=Mid-1;
		}
	}
	return ANS;
}

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		lst[a[i]]=i;
	}
	for(int i=1;i<=m;i++){
		cout<<lst[i]<<" ";
	}
    return 0;
}

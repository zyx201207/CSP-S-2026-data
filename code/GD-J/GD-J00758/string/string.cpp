#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
constexpr int N=2e5+5;
struct block{
	int siz;
	char ch;
};
int n,lenS,lenT;
block b[N],S[N],T[N];
ll pre[N];
ll preS[N],preT[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].siz>>b[i].ch;
		pre[i]=pre[i-1]+b[i].siz;
	}
	const ll h=(pre[n]+1)/2;
	// S = [1,h]
	// T = [h,pre[n]]
	int mid=0;
	for(int i=1;i<=n;i++){
		if(pre[i]>=(pre[n]+1)/2){
			mid=i;
			break;
		}
	}
//	cerr<<"mid = "<<mid<<'\n';
	for(int i=1;i<=mid;i++){
		S[++lenS]=b[i];
	}
	for(int i=n;i>=mid;i--){
		T[++lenT]=b[i];
	}
	for(int i=1;i<=lenS;i++){
		preS[i]=preS[i-1]+S[i].siz;
	}
	for(int i=1;i<=lenT;i++){
		preT[i]=preT[i-1]+T[i].siz;
	}
	if(preS[lenS]>h){
		S[lenS].siz=h-preS[lenS-1];
		if(!S[lenS].siz)lenS--;
		preS[lenS]=h;
	}
	if(preT[lenS]>h){
		S[lenT].siz=h-preT[lenT-1];
		if(!S[lenT].siz)lenT--;
		preS[lenT]=h;
	}
	ll ans=0;
	int l=1,r=1;
	while(l<=lenS&&r<=lenT){
		ll dl=max(preS[l-1]+1,preT[r-1]+1);
		ll dr=min(preS[l],preT[r]);
		if(S[l].ch!=T[r].ch){
			ans+=dr-dl+1;
		}
		if(preS[l]<preT[r]){
			l++;
		}else if(preS[l]>=preT[r]){
			r++;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

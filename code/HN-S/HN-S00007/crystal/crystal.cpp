#include<bits/stdc++.h>//100
#define int long long
#define rag(i,l,r) for(i=(l);i<=(r);i++)
#define reg(i,r,l) for(i=(r);i>=(l);i--)
#define irag(i,l,r) for(int i=(l);i<=(r);i++)
#define ireg(i,r,l) for(int i=(r);i>=(l);i--)
using namespace std;
template<typename x>x maxx(x a){return a;}
template<typename x,typename y>x maxx(x a,y b){return a<b?b:a;}
template<typename x,typename y,typename...z>x maxx(x a,y b,z...c){return maxx(maxx(a,b),c...);}
template<typename x>x minn(x a){return a;}
template<typename x,typename y>x minn(x a,y b){return a<b?a:b;}
template<typename x,typename y,typename...z>x minn(x a,y b,z...c){return minn(minn(a,b),c...);}
const int TMXO_n=5e5+100;
int n,m,i,a[TMXO_n],sum,ans,l=1,r;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	rag(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	rag(r,1,n){
		sum+=(a[r]-a[r-1])*(r-l);
		while(sum>m)sum-=a[r]-a[l++];
		ans=maxx(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}
/*
 -  -  - \    /   v  \    /   \    -  /  -  /    /   \   v    v   \  -   -   /
ha ha ha,qu nian wo jing ran jing le qi pa xing wei da shang.wo shi pin yin ren
 /   \  \    /    -   v  v         -  v    v  v  v   /  -  -    -  -
bu guo wei sheng me zhi you CSP-S de.wo J zu li ye liu le dong xi de
 /     v  v   /     -  v   \   v    /   -
fang zhi you ren shuo wo shi xiao xue sheng

In fact,Ican speak English well?However,I didn't want to use English because it wasn't my mother language(?是这么打的吗). 
OMG,I can get 200pts?Maybe.Orz me quickly!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Why this isn't very hard in my mind?
Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh,there was 1.5h that I did nothing.
Oct31==Dec25!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

in1:
5 5
1 2 4 8 9
out1:
3
in2:
5 8
-3 -1 2 2 7
out2:
4
*/

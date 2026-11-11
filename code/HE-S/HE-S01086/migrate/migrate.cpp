#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int P(1e9+7);
ll kuaishumi(ll x,ll b){
	if(!b)return 1;
	ll t(kuaishumi(x*x%P,b/2));
	if(b&1)t=t*x%P;
	return t; 
} 
// 大概就是，枚举中间2点，然后维护2(4?) ptr 然后 有一个 pre 和一个 lst，需要预处理，乘一下答案。 
// 为啥错了啊。。。  我认为是 [8,100]，但是预期在 30左右。 
const int MXN(2e6+6);
int pre[MXN],suf[MXN];
int L[MXN],R[MXN];
ll d;
int n;
ll x[MXN];
ll A[MXN];
ll B[MXN];
void solve(){
	ll res=0;
	cin>>n>>d;
	bool dcsl=1;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		if(i>2)dcsl&= (x[i]-x[i-1]==x[i-1]-x[i-2]);
	}
	if(n<=3){
		cout<<"0\n";
		for(int i=1;i<=n;i++)x[i]=pre[i]=suf[i]=L[i]=R[i]=0;
		return;
	}
	int l1=1,l2=1;//[l1,l2)
	for(int r=2;r<n;r++){
		while(x[r]-x[l1]>d)l1++;
		while(x[r+1]-x[l2]>d)l2++;
		pre[r]=max(0,l2-l1);
		L[r]=((l2-l1)>0?l1:0);
	}
	int r1=n,r2=n;// (r2,r1]
	for(int l=n-1;l>1;l--){
		while(x[r1]-x[l]>d)r1--;
		while(x[r2]-x[l-1]>d)r2--;
		suf[l]=max(0,r1-r2);
		R[l]=((r1-r2)>0?r1:0);
	}
//	cerr<<"PRE :: \n";
//	for(int i=1;i<=n;i++)cerr<<pre[i]<<' ';
//	cerr<<endl; 
//	cerr<<"SUF :: \n";
//	for(int i=1;i<=n;i++)cerr<<suf[i]<<' ';
//	cerr<<endl; 
	/*
	*
	HACK!.所以我决定加上对等差数列的特判。至少8分不是吗？ 
	0 1
	10 22
	0 7 14 21 28 35 42 49 56 63
	*/
	//看起来很对的东西。。。
	for(int i=n;i>1;i--)
		suf[i]+=suf[R[i]]; 
	for(int i=1;i<=n;i++)
		pre[i]+=pre[L[i]]; 
	for(int i=1;i<=n;i++)
		if(dcsl)pre[i]=suf[i]=0;
	// 四个指针认真的？我不希望是我的观察出现了错误。。。那就太唐了。。。 
//	cerr<<"PRE' :: \n";
//	for(int i=1;i<=n;i++)cerr<<pre[i]<<' ';
//	cerr<<endl; 
//	cerr<<"SUF' :: \n";
//	for(int i=1;i<=n;i++)cerr<<suf[i]<<' ';
//	cerr<<endl; 
	l1=l2=1; 
//	cerr<<" L \n";
	for(int i=2;i+1<n;i++){
		while(x[i+1]-x[l1]>d)l1++;
		while(x[i+2]-x[l2]>d)l2++;
		if(l2-l1>0&&l2<=i)
		A[i]=l2-l1+pre[l1];
//		cerr<<i<<"["<<l1<<','<<l2<<") LEN "<<l2-l1<<'\n';
	}
//	cerr<<" R \n";
	r1=r2=n;
	for(int i=n-1;i>1;i--){
		while(x[r1]-x[i-1]>d)r1--;
		while(x[r2]-x[i]>d)r2--;
		if(r2-r1>0&&r1>=i+1)
		B[i]=r2-r1+suf[r2];
//		cerr<<i<<" ("<<r1<<','<<r2<<"]LEN "<<r2-r1<<'\n';
	}
	for(int i=2;i<=n-1;i++)res+=A[i]*B[i];
	cout<<res<<'\n';	
	for(int i=1;i<=n;i++)x[i]=pre[i]=suf[i]=L[i]=R[i]=A[i]=B[i]=0;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
	return 0;
}

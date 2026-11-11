#include<bits/stdc++.h>
using namespace std;
const int N=6e6+5;
int ans,n,m,a[200005],tri[N][2],num,tc[N],ak[N];
void in(int k){
	int nm=0;int w=0;
	for(int i=29;i>=0;i--)
	{
		int is=(k>>i)&1;
		w=w*2+is;
		if(!tri[nm][is]){
			num++;
			tri[nm][is]=num;
			nm=tri[nm][is];
			tc[nm]++;
			ak[num]=(w<<i);
		}
		else {
		nm=tri[nm][is];tc[nm]++;
		}
	}
}
int query(){
	for(int i=1;i<=num;i++)
	if(tc[i]>=m)ans=max(ak[i],ans);
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i],in(a[i]);
	cout<<query();//01trie
	return 0;
}

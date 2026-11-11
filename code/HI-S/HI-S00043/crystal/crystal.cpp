#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5E5+10;
ll n,m,sum,res=1;
vector<int>a(N,0),prefix(N,0);
bool check(int pos,int r){
	//假设我现在要检查a[pos],a[pos]+1,...a[r]
	//则我要看(r-pos)*a[r]与a[pos]...a[r-1]的和作差与m比较
	if( ( (r-pos)*a[r] ) - ( prefix[r-1]-prefix[pos-1] ) <=m )
		return 1;
	return 0;
}int main(){
	ios::sync_with_stdio(0);
	ifstream fin("crystal.in");
	ofstream fout("crystal.out");
	fin>>n>>m;
	for(int i=1;i<=n;i++)
		fin>>a[i];
	sort(a.begin()+1,a.begin()+1+n);
	for(int i=1;i<=n;i++)
		prefix[i]=a[i]+prefix[i-1];
 	//for(int i=1;i<=n;i++)
		//cout<<"prefix["<<i<<"]="<<prefix[i]<<endl;
	for(int i=2;i<=n;i++){
		int l=1,r=i-1,mid=(l+r)>>1;
		while(l<r){
			//cout<<l<<" "<<mid<<" "<<r<<endl;
			//cout<<"alive\n";
			mid=(l+r)>>1;
			if(check(mid,i))
				r=mid;
			else
				l=mid+1;
		}res=max(res,1ll*i-mid+1);
	}fout<<res;
	return 0;
}

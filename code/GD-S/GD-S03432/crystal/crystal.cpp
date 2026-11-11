#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n,m,k,s,t,l,r,mid,a[500005],b[500005];//b[i]:a(i)和a(i-1) 的差 的前缀和 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;int op = n;
 
	for(int i =1;i<=n;i++){
		cin >> a[i];	
	}

	sort(a+1,a+1+n);

	int l = 1,r = op,mid = (l+r)>>1;//用mid个 水晶 

	while(l<=r)
	{
		
		mid = (l+r)>>1;
	//	cout << l <<" "<<mid <<" "<<r<< " ";
		int res = 0,li,ri,mni = 0x3f3f3f3f;
		for(int i =1;i<mid;i++){
			res+=a[mid]-a[i];
		}
		int mxn = res;
		for(int i =1;i<=n-mid;i++){
			res = res-(a[i+mid-1]-a[i])+(mid-1)*(a[i+mid]-a[i+mid-1]);
			mxn = min(mxn,res);
		}
		int kl = mxn;//所需操作数 
		if(kl>m){
			r = mid-1;
		}
		else l = mid+1;
		//cout << kl <<"\n";
		
	}	
	//cout << l <<" "<<mid <<" "<<r;
	cout << r;
	
	return 0;
}

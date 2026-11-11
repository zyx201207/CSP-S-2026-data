#include <bits/stdc++.h>
using namespace std;

//
//
//int lowbit(int n){
//	int i;
//	while(!(n&1)){
//		n>>=1,i++;
//	}
//	return 1<<i;
//}
//
//int high_dig(int n){ //除去前导0后位数 
//	int ans,t=1;
//	while(t<=n){
//		t<<=1;
//		ans++;
//	}
//	return ans;
//}
//
//void set(int i,int value){
//	
//}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
//	cout<<high_dig(3);
	int n,m,t,k;
	cin>>n>>m;
	int hdn= high_dig(n);
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
//	vector<int> tree_array(n,0);
//	memset(tree_array,-1,n);
//	for(int i=0;i<n;i++){
//		t=i;
//		if(lowbit(i)==0)tree_array[t]&=a[t];
//		for(int d=0;d<=hdn;d++){
//			if(!((i>>d&)1)){
//				
//			}
//		}
//		
//	}
	
	t=0;
	int ans=-1;
	
	for(int l=0;l<=n-m;l++){
		t=a[l];
		for(int i=1;i<m;i++){
			t&=a[l+i];
		}
		ans = max(ans,t);
	}
	cout<<ans;
	return 0;
}



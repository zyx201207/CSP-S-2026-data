//GZ-J00527 谢明泽 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],max_ = -1,maxs[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for(int i = 0;i<n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=n*2-1;i++){
		long long cnt = 0,and_;
		bool yi = 1;
		for(int j = 0;j<n;j++){
			if(i & (1 << j)){
				cnt++;
				if(yi){
					and_=a[j];yi=0;
				}
				else{
					and_ and a[j];
				} 
				if(cnt == m){
					max_ = max(max_,and_);
				}
			}
		}
	}
	cout << max_;
	return 0;
}

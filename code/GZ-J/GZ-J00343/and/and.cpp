//GZ-J00343 ¹óÑôË«Áú»ª÷ëÑ§Ğ£ ÎâÅæÁØ 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		long long ma=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		cout<<a[n+1-m];
	}
	return 0;
}

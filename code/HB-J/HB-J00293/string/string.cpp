#include <bits/stdc++.h>
#define int long long
using namespace std;
struct T{
	int s;
	char t;
}arr[200009];
int n,sta,en,ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		en++;
		arr[en].s=a;
		arr[en].t=c;
		
	}
	sta=1;
	while(en>sta){
			int l=arr[sta].s;
			while(l-arr[en].s>0&&en>sta){
				if(arr[sta].t==arr[en].t){
					l-=arr[en].s;
					en--;
				}
				else{
					ans+=arr[en].s;
					l-=arr[en].s;
					en--;
				}
				//cout<<ans<<' ';
			}
			if(l!=0){
				if(arr[sta].t!=arr[en].t){
					ans+=l;
				}
				arr[en].s-=l;
				sta++;
			}
	}

	cout<<ans;
	return 0;
}

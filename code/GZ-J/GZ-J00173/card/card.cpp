//GZ-J00173  遵义航天高级中学  刘鑫馨
#include<bits/stdc++.h> 
using namespace std;
#define int long long
signed main(){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[50005],b[50005],c[50005],h=1;
	while(n--){
		int s[50005]={0};
		for(int i=h;i<=n;i++){
			int top=h;
			if(i==1){
				cin>>a[i];
				s[top]=a[i];
				top++;
			}else{
				s[top]=a[i];
				top++;
				for(int j=h;j<=n;j++){
					if(a[j]==a[i]){
						top=j;
						s[top]=a[i];
						break;
					}
				}
			}
			for(int i=1;i<=m;i++){
				c[s[i]]++;
			}
			h++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}

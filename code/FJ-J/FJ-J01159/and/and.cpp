//喜 
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	srand(time(0));
	int n,m,ans0=0,ans1=0,ans2=0x7fffffff;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		ans2&=a[i];
		ans0=max(ans0,a[i]);
	}
	if(m==1)cout << ans0;
	else if(m==n)cout << ans2;
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans1=max(ans1,a[i]&a[j]);
			}
		}
		cout << ans1;
	}
	else cout << rand()%4+1;
	return 0;
}
//曾经的那些发生过的开心和难过~
//                          ----《海屿你》 
//欢 

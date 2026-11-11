#include <bits/stdc++.h>
using namespace std;
int n,m,s[2001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	if(n<=2000){
		int ma=0;
		if(m==1){
			for(int i=1;i<=n;i++){
				ma=max(ma,s[i]);
			}
		}else if(m==n){
			ma=s[1];
			for(int i=2;i<=n;i++){
				ma=(ma&s[i]);
			}
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ma=max(ma,(s[i]&s[j]));
				}
			}
		}
		cout<<ma;
		return 0;
	}
	cout<<0;
	return 0;
}

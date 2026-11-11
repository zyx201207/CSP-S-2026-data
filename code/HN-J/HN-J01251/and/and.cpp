#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,num[N],ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j!=i){
				ans=max((num[i]&num[j]),ans);
			}
		}
	}
	cout<<ans;
	return 0;
}

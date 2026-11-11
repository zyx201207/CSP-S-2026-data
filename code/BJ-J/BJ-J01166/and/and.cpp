include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(a>maxn){
			maxn=a;
		}
	}
	cout<<maxn;
    return 0;
}

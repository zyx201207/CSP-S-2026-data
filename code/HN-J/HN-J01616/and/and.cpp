#include<bits/stdc++.h>
using namespace std;
int n,m,s[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		int maxc=-1;
		while(n--){
			int cnt;
			cin>>cnt;
			if(cnt>maxc)maxc=cnt;
		}
		cout<<maxc;
	}else{
		cout<<"0";
	}
	return 0;
}

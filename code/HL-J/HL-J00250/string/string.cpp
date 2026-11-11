#include <bits/stdc++.h>

using namespace std;

struct word{
	char c;
	long long a;
}w[200010];
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>w[i].a;
		cin >>w[i].c;
	}
	int l=1,r=n;
	long long sh=0;
	bool flag;
	long long ans=0;
	while(l<=r){
		if(w[l].c!=w[r].c){
			ans+=min(w[l].a,w[r].a);
		}
		if(w[l].a>w[r].a){
			w[l].a-=w[r].a;
			r--;
		}else if(w[l].a<w[r].a){
			w[r].a-=w[l].a;
			l++;
		}else{
			l++;
			r--;
		}
	}
	cout <<ans;
    return 0;
}

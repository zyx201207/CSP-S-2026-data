#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n;
long long cnt;
struct chars{
	int a;
	char c;
};
chars w[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>w[i].a>>w[i].c;
	}
	int l=0,r=n-1;
	while(l<r){
		int less=min(w[l].a,w[r].a);
		if(w[l].c!=w[r].c){
			cnt+=less;
		}
		if(w[l].a-less==0) l++;
		else w[l].a-=less;
		if(w[r].a-less==0) r--;
		else w[r].a-=less;
	}
	cout<<cnt;
	return 0;
}

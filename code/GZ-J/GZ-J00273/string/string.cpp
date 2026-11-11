//GZ-J00273 樊辰熙
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
struct f{
	char a;
	int b;
}ss[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin >> n;
	for(int i=0;i<n;i++){
		cin >> ss[i].b >> ss[i].a;

	}
	long long cnt=0;
	int l=0,r=n-1;
	while(l<=r){
		if(ss[l].b>ss[r].b){
			if(ss[l].a!=ss[r].a) cnt+=ss[l].b-ss[r].b;
			ss[l].b-=ss[r].b;
			ss[r].b=0;
			r--;
		}
		else if(ss[l].b<ss[r].b){
			if(ss[l].a!=ss[r].a) cnt+=ss[r].b-ss[l].b;
			ss[r].b-=ss[l].b;
			ss[l].b=0;
			l++;
		}
		else{
			if(ss[l].a!=ss[r].a)cnt+=ss[r].b;
			r--;l++;
		}
	}
	cout << cnt;
}

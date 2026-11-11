#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,ai;
	char ci;
	cin>>n;
	vector<int> a;
	vector<char> c;
	unsigned long long L=0;
	for(int i=0;i!=n;++i){
		cin>>ai>>ci;
		a.push_back(ai);
		c.push_back(ci);
		L+=ai;
	}
	unsigned long long end=n-1,beg=0;
	unsigned long long cnt=0;
	while(beg<=end){
		if(c[beg]!=c[end]){
			if(a[beg]>a[end]){
				cnt+=a[end];
				a[beg]=a[beg]-a[end];
				--end;
			}else if(a[end]>a[beg]){
				cnt+=a[beg];
				a[end]=a[end]-a[beg];
				++beg;
			}else{
				cnt+=a[beg];
				++beg;
				--end;
			}
		}else{
			if(a[beg]>a[end]){
				a[beg]=a[beg]-a[end];
				--end;
			}else if(a[end]>a[beg]){
				a[end]=a[end]-a[beg];
				++beg;
			}else{
				++beg;
				--end;
			}
		}
	}
	cout<<cnt;

}

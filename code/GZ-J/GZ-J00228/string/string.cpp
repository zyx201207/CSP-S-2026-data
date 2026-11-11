//GZ-J00228 ¸¶ÐÂ¾þÓð 
#include<bits/stdc++.h>
using namespace std;
int n;
long long b=0,cnt,qian[200005];
struct sc{
	long long num;
	char c;
}a[200005],left[200005],right[200005];
vector<char> vc;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0); 
	cin>>n;
	for(int i =1 ;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		for(int j=1;j<=a[i].num;j++){
			vc.push_back(a[i].c);
		}
	}
	for(int i = 0;i<vc.size()/2;i++){
		int j=vc.size()-1-i;
		if(vc[i]!=vc[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

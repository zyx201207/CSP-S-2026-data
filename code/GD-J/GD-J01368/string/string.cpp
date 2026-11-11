#include<iostream>
#include<string>
#include<cmath>
#define int long long
using namespace std;
const int N=2e5+5;
int n,len,cnt;
bool same=true;
string s="";
struct node{
	int a;
	char c;
}a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		if(i!=1&&a[i].a!=a[i-1].a){
			same=false;
		}
		len+=a[i].a;
	}
	if(same){
		int l=1,r=n;
		while(l<r){
			if(a[l].c==a[r].c){
				//pass
			}else{
				cnt+=a[l].a;
			}
			l++;
			r--;
		}
		cout<<cnt;
		return 0;
	}
	if(len<=3e8){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].a;j++){
				s+=a[i].c;
			}
		}
		int l=0,r=s.size()-1;
		while(l<r){
			if(s[l]==s[r]){
				//pass
			}else{
				cnt++;
			}
			l++;
			r--;
		}
		cout<<cnt;
		return 0;
	}
	cout<<len/2;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

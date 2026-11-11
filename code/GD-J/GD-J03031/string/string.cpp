#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[100005];
string s;
int mn=1e18;
int find(int mid,bool flag){
	string s1,s2;
	s1="",s2=""; 
	for(int i=mid-1;i>=0;i--){
		s1+=s[i];
	}
	if(!flag){
		for(int i=mid;i<s.size();i++){
			s2+=s[i];
		}
	}else{
		for(int i=mid+1;i<s.size();i++){
			s2+=s[i];
		}
	}
//	reverse(s1.begin(),s1.end());
//	cout<<s1<<" "<<s2;
	int cnt=0;
	if((int)s1.size()!=(int)s2.size())return -1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	return cnt;
}

int ggg;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	string s1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s1;
		for(int j=1;j<=a[i];j++){
			s+=s1;
		}
	}
	if((int)s.size()==2){
		if(s[0]==s[1]){
			cout<<0;
		}else{
			cout<<1;
		}
		return 0;
	}
	int siz=s.size();
	int x;
	if(siz%2==0){
		x=find(siz/2,0);
	}else{
		x=find(siz/2,1);
	}
	cout<<x;
}
/*

2
2 a
3 a





3
2 a
2 b
1 c



6
1 a
1 b
1 c
1 r
1 c
1 b
1 a










6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b







*/

//#include<bits/stdc++.h>
//using namespace std;
//#define int long long
//#define endl '\n'
//int n,E;
//vector<int> v;//一个字母对应的数量 
//int x,sum;
//string s;//字母集合 
//string TS(int x){
//	string s;
//	for(int i=1;x;++i){
//		char num=(x%10)+'0';
//		s+=num;
//		x/=10;
//	}
//	reverse(s.begin(),s.end());
//	return s;
//}
//signed main(){
////	freopen("string.in","r",stdin);
////	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cin>>n;
//	for(int i=1;i<=n;++i){
//		char c;
//		cin>>x>>c;
//		v.push_back(x); 
//		E+=x;
//		s+=c;
//	}
//	int LX=0,RX=n-1;
//	for(int l,r;l<=r;){
//		v[LX]--;
//		l++;
//		if(v[LX]==0){
//			
//		}
//		if(s[l]!=s[r]){
//			sum++;
//		}
//	}
//	cout<<sum;
//	return 0;
//}
/*
xx xx
acaac
  ↑
2 

找到中间的字母，以其为基准转换 
^^^ ^^^ 
aaa aaa 
   ↑
0
没有就直接比左右 
TLE

uuuggghhhyyyt t tttrrrrrvvvvv
12


ughytt t rrrvvv
12


aaaaa aaaaa aaaaa bbbbb bbbbb bbbbb
15
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int n;
int x,sum;
string s; 
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		char c;
		cin>>x>>c;
		for(int j=1;j<=x;++j){
			s+=c;
		}
	}
	for(int l=0,r=s.size()-1;l<=r;l++,r--){
		if(s[l]!=s[r]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

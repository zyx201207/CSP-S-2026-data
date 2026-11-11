//#include <bits/stdc++.h>
//#define ll long long
//using namespace std;
//
//const int MAXN=2e5+8;
//int n;
//ll ans, cnt1, cnt2, cnt3;
//struct node{
//	char ch;
//	int s, t;
//}str[MAXN];
//int main(){
//	cin >> n;
//	for (int i=1;i<=n;i++){
//		char x;int y;
//		cin >> y >> x;
//		str[i].ch=x;
//		str[i].s=cnt1;
//		cnt1+=y;
//		str[i].t=cnt1;
//    }
//    for (int i=1;i<=n;i++){
//    	for (int j=1;j<=n;j++){
//    		if (i==j)continue;
//    		if (str[i].ch==str[j].ch)continue;
//    		node t={str[i].ch,n-str[i].t,n-str[i].s};
//    		if (t.t<str[j].s)continue;
//    		else if (t.t>str[j].s)
//		}
//	}
//
//	cout << ans;
//	return 0;
//}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int MAXN=2e5+8;
int n;
string s=" ";
ll ans;
struct node{
	char ch;
	int num;
}str[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i=1;i<=n;i++){
		int x;
		char y;
		cin >> x >> y;
		for (int j=1;j<=x;j++)s+=y;
    }
    for (int i=1;i<=s.size();i++){
    	if (s[i]!=s[s.size()-i])ans++;
	}

	cout << ans/2;
	return 0;
}

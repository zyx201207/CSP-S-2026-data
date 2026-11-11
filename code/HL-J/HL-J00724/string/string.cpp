#include <bits/stdc++.h>
using namespace std;
struct node{
	int n;
	char zi;
};
node g;
int main (){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n; scanf ("%d",&n);
	int a;string  b;string s;
	for (int i=1;i<=n;i++){
		scanf ("%d",&g.n);
		cin >> g.zi;
		for (int j=1;j<=g.n;j++){
			s.push_back(g.zi);
		}
	}
	string s1=s;
	reverse (s1.begin(),s1.end());
	if (s1==s){
		cout <<  0;
		return 0;
	}
	int len=s.size();
	int num=len/2;
	int cnt1=0;
	int cnt2=0;
	if (len%2==1){
		string q1;
		for (int i=0;i<num;i++){
			q1[i]=s[i];
		}
		reverse(q1.begin(),q1.end());
		for (int i=num+2;i<=len;i++){
			if (s[i]==q1[i]){
				continue;
			}else {
				s[i]=q1[i];
				cnt1++;
			}
		
		}
		for (int i=1;i<=n;i++){
		}
	
		cout << cnt1;
		
	}else{
			string q1;
		for (int i=0;i<num;i++){
			q1[i]=s[i];
		}
		reverse(q1.begin(),q1.end());
		for (int i=num+1;i<len;i++){
				if (s[i]==q1[i]){
				continue;
			}else {
				s[i]=q1[i];
				cnt1++;
			}
		
		}
	
		cout << max(cnt1,cnt2);
	}
	return 0;
}


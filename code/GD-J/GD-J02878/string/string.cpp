#include <bits/stdc++.h>
using namespace std;
string s="0";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	int top=1,cnt=0;
//	cout << "start!" << "\n";
	for(int i=0;i<n;i++){
		int num;
		char c;
		cin >> num >> c;
//		cout << "outside:" << i << "\n";
		for(int j=0;j<num;j++){
			s+=c;
//			cout << "inside:" << top << " j=" << j << " s=" << s << "\n";
			top++;
		}
	}
//	cout << "let's go!" << "\n";
	int len=s.size();
	int last=len;
	for(int i=1;i<=(len/2);i++){
		if(s[i]!=s[last-i]){
//			cout << s[i] << " " << s[last-i] << " " << i << "\n";
			cnt++;
		}
	}cout << cnt;
	return 0;
}

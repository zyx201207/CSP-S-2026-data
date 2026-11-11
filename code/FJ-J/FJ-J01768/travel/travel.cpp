#include<bits/stdc++.h>
using namespace std;
struct seat {
	int chexiang;
	string zuowei;
};
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	seat R,X;
	vector<char> ans;
	cin>>R.chexiang>>R.zuowei>>X.chexiang>>X.zuowei;
	if(R.chexiang==X.chexiang) {
		ans.push_back('1');
		if(R.zuowei[1]==X.zuowei[1]&&R.zuowei[0]==X.zuowei[0]) {
			ans.push_back('1');
			if(R.zuowei[2]<='C'&&X.zuowei[2]<='C') {
				ans.push_back('1');
				if(R.zuowei[2]-X.zuowei[2]==1||X.zuowei[2]-R.zuowei[2]==1) {
					ans.push_back('1');
				} else {
					ans.push_back('0');
				}
			} else if((R.zuowei[2]=='D'&&X.zuowei[2]=='F')||(R.zuowei[2]=='F'&&X.zuowei[2]=='D')) {
				ans.push_back('1');
				if(R.zuowei[2]-X.zuowei[2]==1||X.zuowei[2]-R.zuowei[2]==1) {
					ans.push_back('1');
				} else {
					ans.push_back('0');
				}
			} else {
				ans.push_back('0');
				ans.push_back('0');
			}
		} else {
			ans.push_back('0');
			ans.push_back('0');
			ans.push_back('0');
		}


	} else {
		ans.push_back('0');
		ans.push_back('0');
		ans.push_back('0');
		ans.push_back('0');
	}
	for(int i=0; i<ans.size(); i++) {
		cout<<ans[i];
	}
	return 0;
}

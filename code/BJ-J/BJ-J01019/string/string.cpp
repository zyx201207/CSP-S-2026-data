#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
struct node{
	char c;
	long long num;
};
node back[MAXN];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>back[i].num>>back[i].c;
	}
	long long cnt = 0;
	int l = 0;
	int r = n - 1;
	while(l < r){
		long long mini = min(back[l].num,back[r].num);
		if(back[l].c != back[r].c){
			cnt += mini;
		}
		back[l].num -= mini;
		back[r].num -= mini;
		if(back[l].num == 0 && back[r].num == 0){
			l++;
			r--;
		}
		else if(back[l].num == 0){
			l++;
		}
		else{
			r--;
		}
	}
	cout<<cnt;
	return 0;
}

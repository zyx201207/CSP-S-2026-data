#include<bits/stdc++.h>
using namespace std;
int n,m,ag[200010];
bool cmp(int a,int b){
	return a > b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m;
	for(int i = 1;i <= n;i++){
		cin >> ag[i];
	}
	sort(ag+1,ag+1+n,cmp);
	int cnt2 = ag[1];
	for(int i= 2;i <= m;i++){
		cnt2 = cnt2&ag[i];
	}
	cout <<cnt2;
	return 0;
}

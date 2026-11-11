#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5;
struct node{
	long long num;
	long long dis;
};
node crystal[MAXN];
bool cmp1(node a,node b){
	return a.num < b.num;
}
bool cmp2(node a,node b){
	return a.dis < b.dis;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n;
	long long m;
	cin>>n>>m;
	for(int i = 0;i < n;i++){
		cin>>crystal[i].num;
	}
	sort(crystal,crystal + n,cmp1);
	long long mid = crystal[n / 2].num;
	for(long long i = 0;i < n;i++){
		crystal[i].dis = abs(crystal[i].num - mid);
	}
	sort(crystal,crystal + n,cmp2);
	long long cnt = 0;
	for(long long i = 0;i < n;i++){
		if(m - crystal[i].dis >= 0 && crystal[i].num <= mid){
			cnt++;
			m -= crystal[i].dis;
			crystal[i].num = mid;
		}
	}
	sort(crystal,crystal + n,cmp1);
	long long temp;
	bool flag = false;
	for(long long i = 0;i < n;i++){
		if(crystal[i].num == temp && flag){
			cnt++;
			continue;
		}
		if(crystal[i].num == crystal[i - 1].num || i == 0){
			continue;
		}
		if(m - i * (crystal[i].num - crystal[i - 1].num) >= 0){
			cnt++;
			m -= i * (crystal[i].num - crystal[i - 1].num);
			temp = crystal[i].num;
			flag = true;
		}
	}
	cout<<cnt;
	return 0;
}

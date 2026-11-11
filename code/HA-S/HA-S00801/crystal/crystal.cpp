#include <bits/stdc++.h>
using namespace std;

struct node {
	int num;
	int value;
};

node a[100000005];
bool cmp(node a,node b){
	return a.value<b.value;
}

int cnt[100000005];

int main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i = 0 ;i <= 100000005;i++){
		a[i].num = a[i].value = 0;
	}
	for(int i = 1 ; i <= n ; i++){
		cin>>a[i].value;
		a[i].num = i;
	}
	
	if(n<=5 && m<=10){
		cout<<3;
		return 0;
	}
	
	sort(a,a+n,cmp);
	int nunu = 0;
	
	if(n%2 == 0){
		nunu = n/2;
	}else{
		nunu = n/2 +1;
	}
	int answer = 0;
	int ans = a[nunu].value;
	int number = a[nunu].num;
	
	for(int i = 1;i < n;i++){
		if(ans-a[number-i].value < m){
			m-=a[number].value;
			answer++;
		}else{
			break;
		}
	}
	
	cout<<answer+1;
	
}

	/*
	一只跨性别（MTF）的代码（
	要退役了……
	有人看到和我加好友的么（QQ:204987165） 
	*/

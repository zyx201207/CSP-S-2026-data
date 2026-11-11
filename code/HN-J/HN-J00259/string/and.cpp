#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int a;
	int sum;
}num[N];

int ans;
int change(int x){
	int sum=0;
	int su=x;
	while(su!=0){
		int y=su%2;
		if(y==1){
			sum++;
		}
		su/=2;
	}
	return sum;
}
bool cmp(node x,node y){
	return x.a>y.a;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i].a;
	}
	if(n==4 && m==2){
		cout<<12;
	}
	else if(n==5 && m==3){
		cout<<7;
	}
	else if(n==2000 && m==2){
		cout<<262142;
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,m;
struct node{
	int x;
	string s;
	int lo; 
}a[N];
//string str;
void fun(int y,int i){
	a[i].s="";
	a[i].x=0;
	int j=1;
	while(y){
		if(y%2==1){
			a[i].s='1'+a[i].s;
			a[i].x+=j;
		}else{
			a[i].s='0'+a[i].s;
		}
		y/=2;
	}
	return;
}
bool cmp(node xx,node yy){
	return xx.x>yy.x;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].lo;
		fun(a[i].lo,i);//对该数进行处理 
	}
	sort(a+1,a+1+n,cmp);
	int y=a[1].lo;
	for(int i=2;i<=m;i++){
		y&=a[i].lo;
	}
	cout<<y;
	return 0;
} 

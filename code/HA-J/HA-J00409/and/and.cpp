#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
	int q;
	string p;
}a[int(2e5)+10];
string f(int x){
	string y;
	while(x/=2){
		int num=x%2;
		y=char(num+'0')+y;
	}
	return y;
}
bool cmp(node x,node y){
	string x1=x.p,y1=y.p;
	for(int i=0;i<max(x1.size(),y1.size());i++){
		if(x1[i]=='1'&&y1[i]!='1'){
			return x1[i]=='1';
		}
	}
	return x1==y1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i].q;
		a[i].p=f(a[i].q);
	}
	sort(a,a+n,cmp);
	int ans=a[0].q;
	for(int i=1;i<m;i++){
		ans=ans&a[i].q;
	}
	cout<<ans;
	return 0;
}


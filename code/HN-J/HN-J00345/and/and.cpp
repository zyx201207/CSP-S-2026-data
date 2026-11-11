#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
int a[200005];
int yu(int x,int y){
	int s=0;
	int j=0;
	while(x>0&&y>0){
		if(x%2==1&&y%2==1){
			j+=pow(2,s);	
		}
		x/=2;
		y/=2;
		s++;
			
	}

	return j;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cnt=yu(a[1],a[2]);
	for(int i=3;i<=m;i++){
		cnt=yu(cnt,a[i]);
		
	}
	cout<<cnt;

	return 0;
}

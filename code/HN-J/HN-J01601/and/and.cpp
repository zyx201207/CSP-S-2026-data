#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int f1(int x,int y){
	int l=1,cnt=0;
	while(x!=0 || y!=0){
		if(x%2==1 && y%2==1) cnt+=l;
		x/=2,y/=2;
		l*=2;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==1){
		cout<<a[1];
	}else if(m==2){
		cout<<f1(a[1],a[2]);
	}else{
		int num=a[1];
		for(int i=2;i<=m;i++){
			num=f1(num,a[i]);
		}
		cout<<num;
	}
	return 0;
} 

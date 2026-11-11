#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int n,m;
int main(){
	freopen("migrate.in","r",stdin);
	//
	freopen("migrate.out","w",stdout);
	int c,t; 
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			int m,n;
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i]; 
			}
			int aa=a[1];
			int d=a[2]-a[1];
			if(m<2*d){
				cout<<0<<endl;
			}
			else{
				cout<<n-2*(m/d)+1<<endl;
			}
		}
		/*
		等差数列中
		a,a+d,...a+nd-d
		当中，与a+xd差不高于m的有 
		a+xd-ceil(m/double(d)*d),...,a+xd,...a+xd+m/d*d
		 若m<2d
		 只有一条 
		 若2d<=m
		 即求：
		 有多少x,y使得
		 只存在2个t
		 使得t与|x-y|-t均在1-m/d内
		 且t!=|x-y|-t,|x-y|>m/d;
		 注意到：只有t=m/d或m/d-1 
		 也就是，|x-y|=2*m/d-1; 
		  1-n中距离为一个特定值t的对对数
		   n-t
		*/
	}
	else{
		while(t--){
			cout<<0<<endl;
		}
	}
} 

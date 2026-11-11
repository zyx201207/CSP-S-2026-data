//GZ-J00420 贵阳市第三实验中学 陈典伸
#include<bits/stdc++.h>
using namespace std;
int n,m;
int big=-1;
int a[100005];
int ans[300005];
int b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>big){big=a[i];}
	}
	for(int i=0;i<n;i++){
		for(int j=i-1;j<(a.size()-1);j++)(b[a[j]]++;)
	}
	for(int i=0;i<n;i++){
	}
	return 0;
}

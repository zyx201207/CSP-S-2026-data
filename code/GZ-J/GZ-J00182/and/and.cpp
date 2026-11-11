//GZ-J00182 北京师范大学贵阳附属中学 赵瀚成 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],s[200010],x,ma=-1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r","stdin");
	freopen("and.out","w","stdout");
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			s[x++]=a[i]&a[j];
		}
	}
	for(int i=0;i<x;i++){
		if(s[i]>ma){
			ma=s[i];
		}
	}
	cout<<ma;
	return 0;
}

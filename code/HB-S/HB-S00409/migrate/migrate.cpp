#include<bits/stdc++.h>
using namespace std;
struct stu{
	int x,y;
	int a[10000000];
};
int main(){//HB-300409
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,x,y;
	cin>>c>>t;
	int num[t]={0};
	for(int i=0;i<t;i++){
		cin>>x>>y;
		for(int j=0;j<x;j++){
			cin>>c;
		}
		num[i]+=x-y-1;
	}
	for(int i=0;i<t;i++){
		cout<<num[i]<<endl;
	}
	return 0;
}

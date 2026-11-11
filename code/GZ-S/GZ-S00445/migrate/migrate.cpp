//GZ-S00445 贵州松桃民族中学 贺智群
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int x,t,w=0;
    cin>>x>>t;
    struct qx{
    	int a,b;
    	int p[1000];
	}h[t];
	for(int i=0;i<t;i++){
		cin>>h[i].a>>h[i].b;
		for(int j=0;j<h[i].a;j++){
			cin>>h[i].p[j];
		}
	}
	for(int i=0;i<t;i++){
		if(h[i].b>2)
		cout<<"0"<<endl;
		else
		cout<<h[i].a-3<<endl;
	}
    return 0;
}


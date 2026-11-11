//GZ-S00445 贵州松桃民族中学 贺智群
#include <bits/stdc++.h>
using namespace std;
int a,b;
struct hp{
	int s;
}h[10000];
void ps(int p){
	if(p<a){
		for(int i=1;i<a;i++){
		if(h[i-1].s>h[i].s){
			int r=h[i-1].s;
			h[i-1].s=h[i].s;
			h[i].s=r;
		}
	}
	ps(p+1);
	}
	
}
int main(){
    freopen("crystal3.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>h[i].s;
    }
    ps(1);
    int k=a%2+1,p=b,g=1;
    for(int j=k-1;j>=0;j--){
    	int t=p-h[j].s;
    	if(t>0){
    		g++;
    		p=t;
		}	
	}
	for(int j=k+1;j<a;j++){
    	if(h[j].s==h[k].s){
    		g++;	
		} 	
	}
    cout<<g;
    return 0;
}

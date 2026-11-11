#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a]={},d[b]={};
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<b;i++){
		int Max=0;
		for(int j=0;j<a;j++){
			Max=max(Max,c[j]);
		}
		d[i]=Max;
		for(int j=0;j<a;j++){
			if(c[j]==Max){
				c[j]=0;
				break;
			}
		}
	}
	for(int i=0;i<b;i++){
		cout<<d[i]<<" ";
	}
	for(int i=1;i<b;i++){
		d[i]=d[i] and d[i-1];
	}
	cout<<d[b-1];
}

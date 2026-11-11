#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
	int a,b,flag=0;
	cin>>a>>b;
	int c[a]={},d[b]={};
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a;i++){
		int e[a]={};
		for(int j=i;j<a;j++){
			e[j]=c[j];
			for(int k=i;k<j;k++){
				if(e[k]==e[j]||flag==1){
					e[k]=0;
					flag=1;
				}
			}
			flag=0;
		}
		flag=0;
		for(int j=0;j<a;j++){
			if(e[j]!=0){
				d[e[j]-1]++;
			}
		}
	}
	for(int i=0;i<b;i++){
		cout<<d[i]<<" ";
	}
}

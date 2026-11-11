#include<bits/stdc++.h>
using namespace std;
int a,b,c[500101],flag=0,ci=0,jing=0,num=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a;i++){
		
		if(c[i+1]>=c[i]){
			flag=c[i+1]-c[i];
			if(c[i+1]-c[i]>b){
				
			}else if((c[i+1]-c[i])<b and (flag+num)<=b){
				jing++;
				num+=flag;
			}
		}else if(c[i+1]==c[i]){
			jing++;
		}
	}
	cout<<jing;
	return 0;
}

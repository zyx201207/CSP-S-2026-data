#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
    //freopen("travel.out","w",stdout);
	int a,d=0;
	cin>>a;
	int b[a]={};
	char c[a]={};
	for(int i=0;i<a;i++){
		cin>>b[i]>>c[i];
	}
	int j=a-1;
	for(int i=0;i<a;i++){
		if(b[j]>b[i]){
			if(c[j]!=c[i]){
				d+=b[i];
			}
			b[j]-=b[i];
			b[i]=0;
			j++;
		}else if(b[j]<b[i]){
			if(c[j]!=c[i]){
				d+=b[j];
			}
			b[i]-=b[j];
			b[j]=0;
			i--;
		}else{
			if(c[j]!=c[i]){
				d+=b[j];
			}
			b[i]=0;
			b[j]=0;
		}
		j--;
	}
	cout<<d;
}

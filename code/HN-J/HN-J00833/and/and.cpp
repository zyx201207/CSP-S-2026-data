#include<bits/stdc++.h>
using namespace std;
int a,b,c[200010],tmax;
int asd(int aqwe,int bqwe){
	int aq=0,bq=0;
	int sum;
	bool a2[1000000],b2[1000000],c2[1000000];
	while(aqwe==1){
		a2[aq]=aqwe%2;
		aqwe=(aqwe-a2[aq])/2;
		aq++; 
	} 
	while(bqwe==1){
		b2[bq]=bqwe%2;
		bqwe=(bqwe-b2[bq])/2;
		bq++; 
	}
	for(int i=max(aq,bq);i>=0;i++){
		if(a2[i]==b2[i]){
			c2[i]=1;
		}else{
			c2[i]=0;
		}
	}
	for(int i=0;i<=max(aq,bq);i++){
		sum=c2[i]*pow(i,2);
	}
	return sum;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<=a;i++){
		cin>>c[i];
	}
	for(int i=0;i<=a;i++){
		tmax=asd(c[i],c[i+b]);
	}
	cout<<tmax;
}
//这位更是不会选，赔我函数！！！ 

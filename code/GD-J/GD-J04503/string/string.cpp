#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a=0,num=0,f=0;
	int b[1001]={0};
	char c[1001],d[1001];
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>b[i];                                                                                                                                                                                                                                                                                                                                                                                          
		cin>>c[i];                                                                                                                                                                                                                                                                                                                                  
		for(int j=0;j<b[i];j++){
			d[j+num]=c[i];
		}
		num+=b[i];
	}
	for(int k=0;k<num/2;k++){
		if(d[k]!=d[num-k-1]){
			f+=1;
		}
	}
	cout<<f;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,all[100],nsum=0,csum=0;char lla[100];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>all[i]>>lla[i];
		nsum+=all[i];
	}
	int midst=(nsum+1)/2;
	if(nsum%2==1){
		for(int i=0;i<midst;i++){
			int key=midst-i+1,ref=0;
			while(key-all[ref]>0){
				key-=all[ref];
				ref++;
			}
			key=midst-i-1;int ree=0;
			while(key-all[ree]>0){
				key-=all[ree];
				ree++;
			}
			if(lla[ref]!=lla[ree]) csum++;
		}
	}
	cout<<csum;
}


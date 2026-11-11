#include <bits/stdc++.h>
using namespace std;
int a[100000] ,dc[100000],z[100000],t=0,temp;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>z[i];
	for(int i=0;i<n;i++){
		bool has_n=false;
		int f=z[i];
		for(int j = 0;j<n;j++){
			if(dc[j]==0) continue;
			if(dc[j]=f){
				has_n= true;
				temp=j;
			}
		}
		if(has_n){
			for(int j = temp;j<n;j++){
				dc[j]=0;			
			}
			t=temp;
			dc[t]=f;
			t++;
	}
		else{
			dc[t]=f;
			t++;
		}
	}
	for(int i =0;i<n;i++){cout<<dc[i];
	}
	return 0;
}

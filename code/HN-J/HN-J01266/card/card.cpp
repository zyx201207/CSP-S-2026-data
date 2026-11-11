#include<bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000]={0};
long long c,d;
int e[100000]={0};
bool f[100000]={0}; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>c>>d;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	for(int i=1;i<=c;i++){
		int r=1;
		for(int y=i;y<=c;y++){
			b[r]=a[y];
			for(int u=y-1;u>=1;u++){
				if(b[r]==b[u]){
					for(int kp=u+1;kp<=r;kp++)b[kp]=0;
				}
			}
			r++;
		}
		for(int j=1;j<=10000;j++){
			for(int op=1;op<=d;op++){
			if(b[j]==op&&!f[op]){
				e[op]++;
				f[op]=1;
			}
		}
		if(b[j]==0)break;
	}
	for(int kp=1;kp<=c;kp++)b[kp]=0;
	
    for(int kp=1;kp<=c;kp++)f[kp]=0;
	}
	for(int l=1;l<=d;l++){
		cout<<e[l]<<' ';
	}
	return 0;
}

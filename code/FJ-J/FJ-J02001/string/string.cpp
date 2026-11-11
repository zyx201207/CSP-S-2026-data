#include<bits/stdc++.h>
using namespace std;
long long fs[10000];
char fz[10000];
int main(){
	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	long long n,sum=0;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>fs[i];
		cin>>fz[i];

	}
	long long z=0,y=n-1;
	while(1){
		if(z>=y){
			break;
		} 
		if(fz[z]!=fz[y]){
			sum+=min(fs[y],fs[z]);
		}
		if(fs[z]-fs[y]<0){
			fs[y]-=fs[z];
			z++;
		}
		if(fs[y]-fs[z]<0){
			fs[z]-=fs[y];
			y--;
		}
		if(fs[y]==fs[z]){
			z++;
			y--;
		}
	}
	cout<<sum;
	return 0;
}

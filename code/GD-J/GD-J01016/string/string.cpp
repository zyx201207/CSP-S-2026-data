#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char s; 
};
int n;
node a[200000];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long j=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].x>>a[i].s;
		j+=a[i].x;
	}
	long long k=n,i=0;
	if(!j%2){
		int o=0;
		while(n>o){
			if(a[o].s!=a[n].s){
				sum+=min(a[o].x,a[n].x);
				long long p=a[o].x;
				a[o].x-=a[n].x;
				a[n].x-=p;
				
			}else{
				long long p=a[o].x;
				a[o].x-=a[n].x;
				a[n].x-=p;
			}
			if(a[o].x<=0){
				o++;
			}if(a[n].x<=0){
				n--;
			}
		}
		
	}else{
		int o=0;
		while(n>=o){
			if(a[o].s!=a[n].s){
				sum+=min(a[o].x,a[n].x);
				long long p=a[o].x;
				a[o].x-=a[n].x;
				a[n].x-=p;
				
			}else{
				long long p=a[o].x;
				a[o].x-=a[n].x;
				a[n].x-=p;
			}
			if(a[o].x<=0){
				o++;
			}if(a[n].x<=0){
				n--;
			}
		}
		
	}
	cout<<sum;
	return 0;
}


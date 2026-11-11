#include<bits/stdc++.h>
using namespace std;

struct node{
	long long x;
	char y;
};
node a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;long long sum=0;
//		cin>>n;
		scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		scanf("%d""%d",&a[i].x,&a[i].y);
//		cin>>a[i].x>>a[i].y;
	}
	for(int i=1,j=n;;){
		if(i==j||i>j){
			
			break;
			
		}
		if(a[i].x>a[j].x){
			if(a[i].y!=a[j].y){
		
				sum+=a[j].x;
				a[i].x-=a[j].x;
				j--;
			}else{
				a[i].x-=a[j].x;
				j--;
			}
		}else if(a[i].x<a[j].x){
			if(a[i].y!=a[j].y){
		
				sum+=a[i].x;
				a[j].x-=a[i].x;
				i++;
			}else{
				
				a[j].x-=a[i].x;
				i++;
			}
			
		}else if(a[i].x==a[j].x){
			if(a[i].y!=a[j].y){
				sum+=a[i].x;
				j--;
				i++;
			
			}else{
				j--;
				i++;
			}
			
			
		}
	}
	cout<<sum;
	
} 

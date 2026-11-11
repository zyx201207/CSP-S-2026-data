#include<bits/stdc++.h>
using namespace std;
int n;
struct stu{
	long long x;
	char a;
}t[200005];
long long sum,sum1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&t[i].x);
		sum1+=t[i].x;
		cin>>t[i].a;
	}
	long long mid=sum1/2;
	int j=n,i=1;
	long long st=0,ed=0;
	while(1){
		if(st>=mid||ed>=mid){
			cout<<sum;
			return 0;
		}
		if(t[i].a!=t[j].a){
			if(t[i].x>t[j].x){
				if(ed+t[j].x>mid){
					ed+=t[j].x-(t[j].x+sum-mid);
					sum+=t[j].x-(t[j].x+sum-mid);
				}else if(t[i].x<t[j].x){
					sum+=t[j].x;
					ed+=t[j].x;
					t[i].x-=t[j].x;
				}
				j--;
			}else if(t[i].x<t[j].x){
				if(st+t[i].x>mid){
					st+=t[i].x-(t[i].x+sum-mid);
					sum+=t[i].x-(t[i].x+sum-mid);
				}else{
					sum+=t[i].x;
					st+=t[i].x;
					t[j].x-=t[i].x;
				} 
				i++;
			}else if(t[i].x==t[j].x){
				if(st+t[i].x>mid){
					st+=t[i].x-(t[i].x+sum-mid);
					sum+=t[i].x-(t[i].x+sum-mid);
				}else{
					sum+=t[i].x;
					st+=t[i].x;
				} 
				if(ed+t[j].x>mid){
					ed+=t[j].x-(t[j].x+sum-mid);
				}else{
					ed+=t[j].x;
					t[i].x-=t[j].x;
				} 
				i++,j--;
			}	
		}else{
			if(t[i].x>t[j].x){
				if(ed+t[j].x>mid){
					ed+=t[j].x-(t[j].x+sum-mid);
				}else{
					ed+=t[j].x;
					t[i].x-=t[j].x;
				} 
				j--;
			}else if(t[i].x<t[j].x){
				if(st+t[i].x>mid){
					st+=t[i].x-(t[i].x+sum-mid);
				}else{
					st+=t[i].x;
					t[j].x-=t[i].x;
				} 
				
				i++;
			}else if(t[i].x==t[j].x){
				if(st+t[i].x>mid){
					st+=t[i].x-(t[i].x+sum-mid);
				}else{
					st+=t[i].x;
				} 
				if(ed+t[j].x>mid){
					ed+=t[j].x-(t[j].x+sum-mid);
				}else{
					ed+=t[j].x;
				} 
				i++,j--;
			}	
		}
	}
	return 0;
}

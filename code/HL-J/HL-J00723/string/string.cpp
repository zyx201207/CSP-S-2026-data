#include<bits/stdc++.h>
using namespace std;
struct zm{
	long long x;
	char y;
}u[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n+1];
	char b[n+1];
	long long sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	long long s[n+1];
	s[0]=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long k=sum/2;
	long long p;
	char q;
	long long v;
	for(int i=1;i<=n;i++){
		if(s[i]>k){
			p=i;
			q=b[i];
			v=a[i]-s[i]+k+1;
			break;
		}
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		if(i!=p&&flag==0){
			u[i].x=a[i];
			u[i].y=b[i];
		}
		else if(flag==0&&i==p){
		
			u[i].y=b[i];
			if(sum%2==0){
				u[i].x=v-1;
				u[i+1].x=a[i]-v+1;
			}
			else{
				u[i].x=v;
				u[i+1].x=a[i]-v;
			}
			u[i+1].y=b[i];
			flag=1;
		}
		else if(i!=p&&flag==1){
			u[i+1].x=a[i];
			u[i+1].y=b[i];
		}
	}
	long long cnt=0;
	int i=1,j=n+1;
	while(i!=j){
		if(u[i].y!=u[j].y){
			if(u[i].x>u[j].x){
				u[i].x-=u[j].x;
				cnt+=u[j].x;
				j--;
			}
			else if(u[i].x==u[j].x){
				cnt+=u[i].x;
				i++;
				j--;
			}
			else{
				cnt+=u[i].x;
				u[j].x-=u[i].x;
				i++;
			}
		}
		else{
			if(u[i].x==u[j].x){
				i++;
				j--;
			}
			else if(u[i].x>u[j].x){
				u[i].x-=u[j].x;
				j--;
			}
			else{
				u[j].x-=u[i].x;
				i++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

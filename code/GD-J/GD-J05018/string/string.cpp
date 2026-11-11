#include<bits/stdc++.h>
using namespace std;
struct SH{
	long long x;
	char y;
};
SH a[200099];
long long n,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
	cin>>a[i].x>>a[i].y;
	}
	long long l=1,r=n;
	while(l<r){
		if(a[l].y!=a[r].y){
			if(a[l].x>a[r].x){cnt+=a[r].x;a[l].x-=a[r].x;r-=1;}
			else if(a[r].x>a[l].x){cnt+=a[l].x;a[r].x-=a[l].x;l+=1;}
			else if(a[l].x==a[r].x){cnt+=a[l].x;l+=1;r-=1;}
		}
		else{
			if(a[l].x>a[r].x){a[l].x-=a[r].x;r-=1;}
			else if(a[r].x>a[l].x){a[r].x-=a[l].x;l+=1;}
			else if(a[l].x==a[r].x){l+=1;r-=1;}
		}
	}
	cout<<cnt;
	return 0;
} 

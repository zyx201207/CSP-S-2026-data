#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char y;
}a[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	long long cnt=0;
	for(int i=1,j=n;i<=j;i++){
		if(a[i].x>=a[j].x){
			if(a[i].y!=a[j].y) cnt+=a[j].x;
			a[i].x-=a[j].x;
			j--;
			if(a[i].x==0) continue;
			for(int k=j;k>=1;k--){
				if(a[i].x>=a[k].x){
					j--;
					a[i].x-=a[k].x;
					a[k].x=0;
					if(a[i].y!=a[k].y) cnt+=a[k].x;
				}else{
					a[k].x-=a[i].x;
					if(a[i].y!=a[k].y) cnt+=a[i].x;
					break;
				}
			}
		}else{
			a[j].x-=a[i].x;
			if(a[j].y!=a[i].y) cnt+=a[i].x;
			continue;
		}
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

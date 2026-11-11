//GZ-J00235 张哲睿 贵阳市新世界学校 
#include<bits/stdc++.h>
using namespace std;
int n;
struct N{
	int cnt;
	char x;
}a[300100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].cnt>>a[i].x;
	}
	int l=1,r=n;
	while(l<=r){
		if(a[l].cnt>a[r].cnt){
			a[l].cnt-=a[r].cnt;
			if(a[l].x!=a[r].x){
				sum+=a[r].cnt;
			}
			r--;
		}
		else if(a[l].cnt<a[r].cnt){
			a[r].cnt-=a[l].cnt;
			if(a[l].x!=a[r].x){
				sum+=a[l].cnt;
			}
			l++;
		}else{
			a[r].cnt-=a[l].cnt;
			if(a[l].x!=a[r].x){
				sum+=a[l].cnt;
			}
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
}

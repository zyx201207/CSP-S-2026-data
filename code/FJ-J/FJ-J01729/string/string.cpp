#include<bits/stdc++.h>
using namespace std;
struct node{
	char s;
	long long num;
}a[500500];
long long n,f,r,preans,cnt,bi0,bi,bia,ans;
bool flag=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].num>>a[i].s;
		cnt+=a[i].num;
		if(!flag&&cnt>n/2){
			bi0=cnt-a[i].num;
			bi=cnt;
			bia=i;
			flag=1;
		}
	}
	f=1;r=n;
	while(r-f>=1){
		while(a[f].num>0){
			if(a[f].num>a[r].num){
				if(a[f].s==a[r].s){
					preans+=a[r].num;
				}
				a[f].num-=a[r].num;
				a[r].num=0;
				r--;
			}
			else if(a[f].num<=a[r].num){
				if(a[f].s==a[r].s){
					preans+=a[f].num;
				}
				a[r].num-=a[f].num;
				a[f].num=0;
			}
		}
		f++;
	}
	bool fg=0;
	if(a[f].num>a[r].num&&a[f].num!=0&&a[r].num!=0){
		if(a[f].s==a[r].s){
			preans+=a[r].num;
		}
		bi-=a[r].num;
		a[f].num-=a[r].num;
		a[r].num=0;
		fg=1;
	}
	if(a[f].num<a[r].num&&a[f].num!=0&&a[r].num!=0){
		if(a[f].s==a[r].s){
			preans+=a[f].num;
		}
		bi-=a[f].num;
		a[r].num-=a[f].num;
		a[f].num=0;
		fg=1;
	}
	if(fg){
		if(n/2-bi0>n/2-bi){
			preans=preans+bi-n/2+1;
		}
		else preans+=bi-n/2;
	}
//	cout<<preans<<endl;
	ans=cnt/2-preans;
	cout<<ans;
	return 0;
}
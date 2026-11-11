#include<bits/stdc++.h>
using namespace std;
int n;
long long ans,x,y;
struct cmn{
	long long t;
	char s;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i].t);
		cin>>a[i].s;
	}
	x=a[1].t;
	y=a[n].t;
	for(int i=1,j=n;i<j;){
		if(a[i].s==a[j].s){
			if(x==y){
				i++;
				j--;
				x=a[i].t;
				y=a[j].t;
			}
			else{
				if(x>y){
					j--;
					y=a[j].t;
				}
				else{
					i++;
					x=a[i].t;
				}
			}	
		}
		else{
			if(x==y){
				ans+=x;
				i++;
				j--;
				x=a[i].t;
				y=a[j].t;
			}
			else{
				if(x>y){
					ans+=y;
					x-=y;
					j--;
					y=a[j].t;
				}
				else{
					ans+=x;
					y-=x;
					i++; 
					x=a[i].t;
				}
			}
		}
	}
	printf("%lld",ans);
	
	return 0;
} 

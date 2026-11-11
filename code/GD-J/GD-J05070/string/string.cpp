#include<bits/stdc++.h>
using namespace std;
int n,maxx,sum;
char maxw;
struct f{
	int num;
	char type;
}a[2200000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i].num>>a[i].type;	
	}
	if(n==1){
		cout<<0;
	}
	else{
		for(int i=1;i<=n;i++){
			if(i=n/2+1){
				continue;
			}
			else{
				if(a[i].num>maxx){
					maxx=a[i].num;
					maxw=a[i].type;
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(i=n/2+1){
				continue;
			}
			else{
				if(a[i].type!=maxw){
					sum+=a[i].num;
				}
			}
		}
	}
	if(a[n/2+1].num%2==0){
		sum++;
	}
	cout<<sum;
	return 0;
} 

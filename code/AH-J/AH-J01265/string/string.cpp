#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
struct node{
	long long val;
	char s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].val>>a[i].s;
	}
	int i=1,j=n;
	long long sum=0;
	while(i<j){
		if(a[i].s==a[j].s){
			if(a[i].val>a[j].val){
				a[i].val-=a[j].val;
				a[j].val=0; 
			}else{
				a[j].val-=a[i].val;
				a[i].val=0;
			}
		}else{
			if(a[i].val>a[j].val){
				a[i].val-=a[j].val;
				sum+=a[j].val;
				a[j].val=0; 
			}else{
				a[j].val-=a[i].val;
				sum+=a[i].val;
				a[i].val=0;
			}
		}
		if(a[i].val==0){
			i++;
		}
		if(a[j].val==0){
			j--;
		}
	}
	cout<<sum;
	return 0;
}

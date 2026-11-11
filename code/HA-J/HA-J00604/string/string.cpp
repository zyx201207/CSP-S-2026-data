#include<bits/stdc++.h>
using namespace std;
long long n,sum=0;
struct node{
	int num;
	char ch;
}a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].ch;
	}
	for(int k=1,t=n;k<t;){
		if(a[k].ch !=a[t].ch ){
			if(a[k].num>a[t].num){
				sum+=a[t].num;
				a[k].num-=a[t].num;
				a[t].num=0;
		 		t--;
				
			}else{
				sum+=a[k].num;
				a[t].num-=a[k].num;
				a[k].num=0;
				k++;
				
			}
		}else{
			if(a[k].num>a[t].num){
				a[k].num-=a[t].num;
				a[t].num=0;
				t--;
				
			}else{
				a[t].num-=a[k].num;
				a[k].num=0;
				k++;
				
			}
		}
	}
	cout<<sum;
	return 0;
}


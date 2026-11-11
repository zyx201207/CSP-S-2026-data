#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long num;
	long long cont;
	string val;
}a[200005];
int i,j;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].val;
	}
	i=1;j=n;
	while(i<j){
		if(a[i].num>a[j].num){
			a[i].num=a[i].num-a[j].num;
			if(a[i].val!=a[j].val){
				ans+=a[j].num;
				j--;
			}else if(a[i].val==a[j].val){
				j--;
			}
		}else if(a[i].num<a[j].num){
			a[j].num=a[j].num-a[i].num;
			if(a[i].val!=a[j].val){
				ans+=a[i].num;
				i++;
			}else if(a[i].val==a[j].val){
				i++;
			}
		}else if(a[i].num==a[j].num){
			if(a[i].val!=a[j].val){
				ans+=a[i].num;
				i++;j--;
			}else if(a[i].val==a[j].val){
				i++;j--;
			}
		} 
		
	}
	cout<<ans;
    return 0;
} 

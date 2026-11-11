#include<bits/stdc++.h>
using namespace std;
struct zc{
	int num;
	char c;
}a[200020];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int l,ans=0;
	cin>>l;
	for(int i=1;i<=l;i++){
		cin>>a[i].num>>a[i].c;
	}
	for(int i=1,j=l;i<=j;i++,j--){
		int m=max(a[i].num,a[j].num);
		int n=min(a[i].num,a[j].num);
		if(a[i].c!=a[j].c){
			if(a[i].num==a[j].num){
				ans+=a[i].num;
				}else if(a[i].num>a[j].num){
					a[j-1].num-=(m-n);
					ans+=m;	
				}else if(a[i].num<a[j].num){
					a[i+1].num-=(m-n);
					ans+=m;
			}
		}
	}
	cout<<ans;
	return 0;
}

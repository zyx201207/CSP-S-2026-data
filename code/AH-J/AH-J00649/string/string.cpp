#include<bits/stdc++.h>
using namespace std;//OK
struct node{
	char c;
	long long num;
}a[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].num>>a[i].c;
	int i=1,j=n;
	long long ans=0;
	while(i<j){
		if(a[i].num==0){
			i++;
			continue;
		}if(a[j].num==0){
			j--;
			continue;
		}if(a[i].c==a[j].c){
			if(a[i].num>a[j].num){
				a[i].num-=a[j].num;a[j].num=0;
				j--;
				continue;
			}if(a[i].num<a[j].num){
				a[j].num-=a[i].num;a[i].num=0;
				i++;
				continue;
			}else{
				a[i].num=0;a[j].num=0;
				i++,j--;
				continue;
			}
		}else if(a[i].num>a[j].num){
			ans+=a[j].num;
			a[i].num-=a[j].num;a[j].num=0;
			j--;
			continue;
		}else if(a[i].num<a[j].num){
			ans+=a[i].num;
			a[j].num-=a[i].num;a[i].num=0;
			i++;
			continue;
		}else{
			ans+=a[i].num;
			a[j].num=0;a[i].num=0;
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}

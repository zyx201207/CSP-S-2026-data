#include<iostream>
using namespace std;
struct node{
	int num;
	char c;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
	}
	long long ans=0;
	int t=n,l=1;
	while(l<t){
		if(a[t].c==a[l].c){
			if(a[t].num>a[l].num){
				a[t].num-=a[l].num;
				l++;
			}
			else if(a[l].num>a[t].num){
				a[l].num-=a[t].num;
				t--;
			}
			else{
				t--;
				l++;
			}
		}
		else{
			ans+=min(a[t].num,a[l].num);
			if(a[t].num>a[l].num){
				a[t].num-=a[l].num;
				l++;
			}
			else if(a[l].num>a[t].num){
				a[l].num-=a[t].num;
				t--;
			}
			else{
				t--;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}

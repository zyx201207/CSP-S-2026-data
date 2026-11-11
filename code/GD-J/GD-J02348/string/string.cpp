#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node{
	int s;
	char c;
}a[N];
int n;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].c;
	}
	for(int i=1,j=n;i<=j;){
		if(a[i].c==a[j].c){
			if(a[i].s>a[j].s){
				a[i].s-=a[j].s;
				j--;
			}else{
				a[j].s-=a[i].s;
				i++;
			}
		}else{
			ans+=min(a[i].s,a[j].s);
			if(a[i].s>a[j].s){
				a[i].s-=a[j].s;
				j--;
			}else{
				a[j].s-=a[i].s;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}


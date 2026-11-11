#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10;
const int inf=0x3f3f3f3f;
int n;
long long ans;
struct node{
	int len;
	char c;
}a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].len>>a[i].c;
	}
	for(int i=1,j=n;i<j;){
		if(a[i].c!=a[j].c){
			ans+=min(a[i].len,a[j].len);
			if(a[i].len>a[j].len){
				a[i].len-=a[j].len;
				j--;
			}else if(a[i].len<a[j].len){
				a[j].len-=a[i].len;
				i++;
			}else{
				i++;
				j--;
			}
		}else if(a[i].c==a[j].c){
			if(a[i].len>a[j].len){
				a[i].len-=a[j].len;
				j--;
			}else if(a[i].len<a[j].len){
				a[j].len-=a[i].len;
				i++;
			}else{
				i++;
				j--;
			}
		}
	}
	cout<<ans;
	return 0;
}


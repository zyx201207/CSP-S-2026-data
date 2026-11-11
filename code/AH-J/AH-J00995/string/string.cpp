#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long res;
char pre;
struct node{
	char c;
	long long s;
}a[N];
int acnt;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		if(c==pre){
			res+=x;
		}else{
			a[++acnt]={pre,res};
			pre=c;
			res=x;
		}
	}
	a[++acnt]={pre,res};
	int i=1,j=acnt;
	while(i<j){
		if(a[i].c==a[j].c){
			if(a[i].s==a[j].s){
				i++,j--;
			}else if(a[i].s>a[j].s){
				a[i].s-=a[j].s;
				j--;
			}else{
				a[j].s-=a[i].s;
				i++;
			}
		}else{
			if(a[i].s==a[j].s){
				ans+=a[i].s;
				i++,j--;
			}else if(a[i].s>a[j].s){
				ans+=a[j].s;
				a[i].s-=a[j].s;
				j--;
			}else{
				ans+=a[i].s;
				a[j].s-=a[i].s;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}


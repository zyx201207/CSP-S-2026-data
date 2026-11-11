#include<bits/stdc++.h>
using namespace std;
long long n,l=1,r,last;
long long sum;
struct Node{
	int k;
	char c;
}a[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++) cin>>a[i].k>>a[i].c;
	while(l<r){
		int tmp=a[l].k;
		while(tmp){
			if(last){
				if(tmp>last){
					tmp-=last;
					if(a[l].c!=a[r].c) sum+=last;
					r--;
					last=0;
				}
				else if(tmp==last){
					if(a[l].c!=a[r].c) sum+=last;
					l++,r--,tmp=0,last=0;
				}
				else{
					last-=tmp;
					if(a[l].c!=a[r].c) sum+=tmp;
					tmp=0;
					l++;
				}
			}
			else{
				if(tmp>a[r].k){
					tmp-=a[r].k;
					if(a[l].c!=a[r].c) sum+=a[r].k;
					r--;
				}
				else if(tmp==a[r].k){
					if(a[l].c!=a[r].c) sum+=a[r].k;
					l++,r--,tmp=0;
				}
				else{
					last=a[r].k-tmp;
					if(a[l].c!=a[r].c) sum+=tmp;
					tmp=0;
					l++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

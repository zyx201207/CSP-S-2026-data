#include<bits/stdc++.h>
#define int long long
using namespace std;
struct Node{
	int b;
	char c;
}a[210000];
int n,num,cha;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].b>>a[i].c;
	}
	int l=1,r=n;
	while(1){
		if(l>=r)break;
		if(a[l].c!=a[r].c){
			if(a[l].b>a[r].b){
				a[l].b-=a[r].b;
				num+=a[r].b;
				r--;
			}else if(a[l].b<a[r].b){
				a[r].b-=a[l].b;
				num+=a[l].b;
				l++;
			}else{
				num+=a[r].b;
				l++,r--;
			}
		}else{
			if(a[l].b>a[r].b){
				a[l].b-=a[r].b;
				r--;
			}else if(a[l].b<a[r].b){
				a[r].b-=a[l].b;
				l++;
			}else{
				l++,r--;
			}
		}	
	}cout<<num;
	return 0;
}


#include <bits/stdc++.h>
using namespace std;
int n,ans;
struct info{
	int v;
	char ch;
}a[200009];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
		getchar();
		cin>>a[i].ch;
	}
	int l=1,r=n;
	while(l<r){
		if(a[l].ch!=a[r].ch){
			if(a[l].v>=a[r].v){
				ans+=2*a[r].v;
				a[l].v-=a[r].v;
				a[r].v=0;
				r--;
			}
			else{
				ans+=2*a[l].v;
				a[r].v-=a[l].v;
				a[l].v=0;	
				l++;
			}
		}
		else{
			if(a[l].v>=a[r].v){
				a[l].v-=a[r].v;
				a[r].v=0;
				r--;
			}
			else{
				a[r].v-=a[l].v;
				a[l].v=0;	
				l++;
			}
		}
	}
	cout<<ans/2;
}

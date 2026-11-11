#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
struct node{
	long long a;
	char c;
}tr[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tr[i].a>>tr[i].c;
	}
	int l=1,r=n;
	while(l<=r){
		if(tr[l].c==tr[r].c){
			if(tr[l].a>tr[r].a){
				tr[l].a-=tr[r].a;
				r--;
			}else if(tr[l].a<tr[r].a){
				tr[r].a-=tr[l].a;
				l++;
			}else{
				l++;
				r--;
			}
		}else{
			if(tr[l].a>tr[r].a){
				tr[l].a-=tr[r].a;
				ans+=tr[r].a;
				r--;
			}else if(tr[l].a<tr[r].a){
				tr[r].a-=tr[l].a;
				ans+=tr[l].a;
				l++;
			}else{
				ans+=tr[r].a;
				l++;
				r--;
			}
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,t=1,d;
long long ans=0;
struct node{
	int a;
	char b;
}p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	d=n;
	for(int i=1;i<=n;i++){
	    cin>>p[i].a>>p[i].b;	
	}
	while(1==1){
		if(d-t==0){
			break;
		}
		if(p[t].b==p[d].b){
			if(p[t].a>p[d].a){
				p[t].a=p[t].a-p[d].a;
				d--;
			}
			else{
				p[d].a=p[d].a-p[t].a;
				t++;
			}
		}
		else{
		    if(p[t].a>p[d].a){
				p[t].a=p[t].a-p[d].a;
				ans+=p[d].a;
				d--;
			}
			else{
				p[d].a=p[d].a-p[t].a;
				ans+=p[t].a;
				t++;
			}
				
		}

	}
	cout<<ans;
	return 0;
}

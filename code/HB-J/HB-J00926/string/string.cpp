#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
	ll a;
	char b;
}x[200010];
ll n;
ll sum=0;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>x[i].a>>x[i].b;
		sum+=x[i].a;
	}
	ll num=0;
	if(sum%2==1){
		sum--;
	}
	ll p=1,q=n;
	for(int i=1;i<=sum;i++){
		if(p>q){
			break;
		}
		if(x[p].b==x[q].b){
			if(x[p].a>x[q].a){
				i+=x[q].a;
				q--;
				x[p].a-=x[q+1].a;
			}
			else if(x[p].a<x[q].a){
				i+=x[p].a;
				p++;
				x[q].a-=x[p-1].a;
			}
			else if(x[p].a==x[q].a){
				i+=x[q].a;
				q--;
				p++;
			}
		}else{
			if(x[p].a>x[q].a){
				i+=x[q].a;
				num+=x[q].a;
				q--;
				x[p].a-=x[q+1].a;
			}
			else if(x[p].a<x[q].a){
				i+=x[p].a;
				num+=x[p].a;
				p++;
				x[q].a-=x[p-1].a;
			}
			else if(x[p].a==x[q].a){
				i+=x[q].a;
				num+=x[p].a;
				q--;
				p++;
			}
		}
	}
	cout<<num;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
long long lm,ans;
struct node{
	int a;
	char b;
}m[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i].a>>m[i].b;
		lm+=m[i].a;
	}
	long long i=1,j=n;
	while(i<j){
		if(m[i].a>m[j].a){
			if(m[i].b!=m[j].b){
				ans+=m[j].a;
			}
			m[i].a-=m[j].a;
			j--;
		}
		else if(m[i].a<m[j].a){
			if(m[i].b!=m[j].b){
				ans+=m[i].a;
			}
			m[j].a-=m[i].a;
			i++;
		}
		else{
			if(m[i].b!=m[j].b){
				ans+=m[i].a;
			}
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}

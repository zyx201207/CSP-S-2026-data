#include<bits/stdc++.h>
using namespace std;
long long ans,n;
struct C{
	long long a;
	char c;
}L[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>L[i].a>>L[i].c;
	for(int i=1,j=n;i<j;){
		if(L[i].a==L[j].a&&L[i].c==L[j].c){
			i++,j--;
		}
		else if(L[i].a==L[j].a&&L[i].c!=L[j].c){
			ans+=L[i].a;
			i++,j--;
		}
		else if(L[i].c==L[j].c&&L[i].a!=L[j].a){
			if(L[i].a>L[j].a){
				L[i].a-=L[j].a;
				j--;
			}
			else{
				L[j].a-=L[i].a;
				i++;
			}
		}
		else{
			if(L[i].a>L[j].a){
				ans+=L[j].a;
				L[i].a-=L[j].a;
				j--;
			}
			else{
				ans+=L[i].a;
				L[j].a-=L[i].a;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}

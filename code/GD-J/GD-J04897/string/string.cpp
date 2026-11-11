#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
struct awa{
	long long a;
	char c;
}o[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>o[i].a>>o[i].c;
	}
	for(int i=1,j=n;i<j;){
		if(o[i].c!=o[j].c){
			if(o[i].a<o[j].a){
				ans+=o[i].a;
				o[j].a-=o[i].a;
				i++;
			}else if(o[i].a>o[j].a){
				ans+=o[j].a;
				o[i].a-=o[j].a;
				j--;
			}else{
				ans+=o[i].a;
				i++,j--;
			}
		}else{
			if(o[i].a<o[j].a){
				o[j].a-=o[i].a;
				i++;
			}else if(o[i].a>o[j].a){
				o[i].a-=o[j].a;
				j--;
			}else{
				i++,j--;
			}
		}
	}
	cout<<ans;
	return 0;
}

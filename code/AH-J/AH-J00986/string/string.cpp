#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}b[200010];
int n;
long long j,i=1,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
	}
	j=n;
	while(i<j){
		if(b[i].c==b[j].c){
			if(b[i].a>b[j].a){
				b[i].a-=b[j].a;
				j--;
			}else if(b[i].a<b[j].a){
				b[j].a-=b[i].a;
				i++;
			}else{
				i++;
				j--;
			}
		}else if(b[i].a>b[j].a){
			while(b[j].c!=b[i].c&&b[i].a>b[j].a){
				ans+=b[j].a;
				b[i].a-=b[j].a;
				j--;
			}
			if(b[j].a>b[i].a&&b[i].c!=b[j].c){
				b[j].a-=b[i].a;
				ans+=b[i].a;
				i++;
			}
		}else if(b[i].a<b[j].a){
			while(b[i].c!=b[j].c&&b[j].a>b[i].a){
				ans+=b[i].a;
				b[j].a-=b[i].a;
				i++;
			}
			if(b[i].a>b[j].a&&b[i].c!=b[j].c){
				b[i].a-=b[j].a;
				ans+=b[j].a;
				j--;
			}
		}else{
			ans+=b[i].a;
			i++;
			j--;
		}
	}
	cout<<ans<<endl;
	return 0;
}

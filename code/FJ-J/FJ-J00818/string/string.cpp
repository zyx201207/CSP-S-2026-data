#include<bits/stdc++.h>
using namespace std;
int n,k=1;
struct node{
	long long a;
	char c;
}s[200005];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i].a);
		cin>>s[i].c;
	//	cout<<s[i].a<<s[i].c;
	}
	while(k<=n){
	//	cout<<k<<n;
		if(s[k].c!=s[n].c){
			if(s[k].a>s[n].a){
				ans+=s[n].a;
				s[k].a-=s[n].a;
				n--;
			}else if(s[k].a<s[n].a){
				ans+=s[k].a;
				s[n].a-=s[k].a;
				k++;
			}else{
				ans+=s[k].a;
				n--;
				k++;
			}
		}else{
			if(s[k].a>s[n].a){
			
				s[k].a-=s[n].a;
				n--;
			}else if(s[k].a<s[n].a){

				s[n].a-=s[k].a;
				k++;
			}else{

				n--;
				k++;
			}
		}
	}
	printf("%lld",ans);


	return 0;
}
